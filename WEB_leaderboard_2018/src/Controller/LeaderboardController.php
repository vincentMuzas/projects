<?php
/**
 * Created by PhpStorm.
 * User: vincent
 * Date: 01/10/18
 * Time: 16:18
 */

namespace App\Controller;


use Sensio\Bundle\FrameworkExtraBundle\Configuration\Route;
use Symfony\Bundle\FrameworkBundle\Controller\AbstractController;

class LeaderboardController extends AbstractController
{
    /**
     * @Route("/")
     */
    public function homepage()
    {
        $em = $this->getDoctrine()->getManager();
        $data = get_homapage($em);

        return $this->render('article/teams.html.twig', [
            'teams' => $data["teams"],
            'wins' => $data["wins"],
            'loses' => $data["loses"],
        ]);
    }

    /**
     * @Route("/{team}")
     */
    public function getTeams($team)
    {
        $em = $this->getDoctrine()->getManager();
        $data = get_team_data($team, $em);

        return $this->render('article/team_page.html.twig', [
            'name' => $data["name"],
            'trueskill' => $data["trueskill"],
            'wins' => $data["wins"],
            'losses' => $data["losses"],
            'matches' => $data["matches"],
            'id' => $team,
        ]);
    }
}

function get_homapage($em)
{
    $data = [];

    $rawSql = "SELECT * FROM teams ORDER BY (skill_mu - 3 * skill_sigma) DESC ;";
    $stmt = $em->getConnection()->prepare($rawSql);
    $stmt->execute();
    $data["teams"] = $stmt->fetchAll();

    $rawSql = "select teams.id, count(matches.id) as wins from teams, matches where winner=teams.id group by id;";
    $stmt = $em->getConnection()->prepare($rawSql);
    $stmt->execute();
    $data["wins"] = $stmt->fetchAll();

    $rawSql = "select teams.id, count(matches.id) as loses from teams, matches where (id_team1=teams.id or id_team2=teams.id) and winner!=teams.id group by id;";
    $stmt = $em->getConnection()->prepare($rawSql);
    $stmt->execute();
    $data["loses"] = $stmt->fetchAll();

    return ($data);
}


function get_team_data($team, $em)
{
    $data = [];
    $querry = "select (skill_mu - 3 * skill_sigma) as value from teams where id=\"".$team."\";";

    $stmt = $em->getConnection()->prepare($querry);
    $stmt->execute();
    $data["trueskill"] = $stmt->fetchAll()[0];

    $querry = "select count(id) as value from matches where winner=(select id from teams where id=\"".$team."\");";
    $stmt = $em->getConnection()->prepare($querry);
    $stmt->execute();
    $data["wins"] = $stmt->fetchAll()[0];

    $querry = "select count(id) as value from matches where (id_team1=(select id from teams where id=\"".$team."\") or id_team2=(select id from teams where id=\"".$team."\")) and winner!=(select id from teams where id=\"".$team."\");";
    $stmt = $em->getConnection()->prepare($querry);
    $stmt->execute();
    $data["losses"] = $stmt->fetchAll()[0];

    $querry = "select name from teams where id=\"".$team."\";";
    $stmt = $em->getConnection()->prepare($querry);
    $stmt->execute();
    $data["name"] = $stmt->fetchAll()[0]["name"];

    $querry = "select matches.id, matches.winner, name as oponent, timediff(end, start) as duration from matches join teams on ((matches.id_team1=teams.id and matches.id_team1!=".$team.") or (matches.id_team2=teams.id and matches.id_team2!=".$team.")) where id_team1=".$team." or id_team2=".$team.";";
    $stmt = $em->getConnection()->prepare($querry);
    $stmt->execute();
    $data["matches"] = $stmt->fetchAll();
    return ($data);
}