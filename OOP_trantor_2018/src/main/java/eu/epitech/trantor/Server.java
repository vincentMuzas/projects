package eu.epitech.trantor;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.*;
import java.nio.channels.IllegalBlockingModeException;
import java.util.ArrayList;

public class Server {
	private int port;
	private ServerSocket socket;
	private ArrayList<Socket> clients;
	private ArrayList<Drone> drones;
	private ArrayList<BufferedReader> clients_reader;
	private Team team;
	public Server(int port) throws IOException {
		this.port = port;
		try {
			this.socket = new ServerSocket(port);
			this.socket.setSoTimeout(50);
			this.clients_reader = new ArrayList<>();
			this.drones = new ArrayList<Drone>();
			this.team = new Team(1, "GRAPHICAL");
			System.out.println("Server started on port " + this.port + " successfully ...\nWaiting for connection ...");
		} catch (IOException e) {
			throw e;
		}
		clients = new ArrayList<>();
	}
	/**
	 * @return the port
	 */
	public int getPort() {
		return port;
	}
	public void run(Map map, Commands commands) {
		Socket local = null;
		Boolean end = false;

		/**
		 * this loop accept connetions with a 20 ms timeout
		 * and put them inside the @clients
		 */
		while (!end) {
			try {
				local = this.socket.accept();
			} catch (IOException e) {
				end = true;
			}
			if (!end) {
				try {
					local.setSoTimeout(20);
					clients.add(local);
					clients_reader.add(new BufferedReader(new InputStreamReader(local.getInputStream())));
					Integer posX = (int)(Math.random() * map.getSizeX());
					Integer posY = (int)(Math.random() * map.getSizeY());
					Integer orientation = (int)(Math.random() * 4);
					drones.add(new Drone(clients.size(), posX, posY, orientation < 1 ? 1 : orientation, 1, this.team));
					System.out.println("New drone with id " + clients.size() + " joined map [" + posX + ", " + posY + "] and oriented " + orientation + ".");
					map.refreshDrones(this.drones);
				} catch (IOException e) {
					System.out.println(e.getMessage());
				}
			}
		}

		/**
		 * read on the input, print it
		 * and echo server at the moment
		 */
		String input = null;
		for (int counter = 0; counter < clients.size(); counter ++) {
			try {
				if (clients.get(counter).getInputStream().available() != 0) {
					while ((input = clients_reader.get(counter).readLine()) != null) {
						System.out.println("Drone " + (counter + 1) + " send : " + input);
						byte msg[];
						if (input.equals("Connect_nbr")) {
							msg = ((Integer)this.clients.size()).toString().getBytes();
						} else {
							msg = commands.handleCommand(input, drones.get(counter)).getBytes();
						}
						clients.get(counter).getOutputStream().write(msg);
						clients.get(counter).getOutputStream().write(new String("\n").getBytes());
						map.refreshDrones(this.drones);
					}
				}
			} catch (IOException e) {

			}
		}
	}
}