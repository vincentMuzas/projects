package com.dashboard.service;

import com.dashboard.model.User;
import com.dashboard.repository.UserRepository;
import lombok.Data;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.Optional;

@Data
@Service
public class UserService {

    @Autowired
    private UserRepository userRepository;

    public Optional<User> getUser(final Long id) {
        return userRepository.findById(id);
    }

    public Optional<User> getUserByEmail(final String email) {
        return userRepository.findByEmail(email);
    }

    public Optional<User> getUserByToken(final String token) {
        return userRepository.findByToken(token);
    }

    public Iterable<User> getUsers() {
        return userRepository.findAll();
    }

    public void deleteUser(final Long id) {
        userRepository.deleteById(id);
    }

    public User saveUser(User employee) {
        return userRepository.save(employee);
    }

    public boolean isLogged(String token)
    {
        Optional<User> user = this.getUserByToken(token);

        if (user.isPresent())
            return true;
        else
            return false;
    }
}
