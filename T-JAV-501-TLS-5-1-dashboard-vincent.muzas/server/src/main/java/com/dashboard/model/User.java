package com.dashboard.model;

import com.dashboard.tool.Usefull;
import com.sun.istack.NotNull;
import lombok.Data;
import org.hibernate.annotations.CreationTimestamp;
import org.springframework.security.crypto.bcrypt.BCryptPasswordEncoder;

import javax.persistence.*;
import javax.validation.constraints.Pattern;
import javax.validation.constraints.Size;
import java.util.Date;
import java.util.Random;

@Data
@Entity
@Table(name = "users")
public class User {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;

    @Column(unique = true)
    @Pattern(regexp=".+@.+\\..+", message="Please provide a valid email address")
    private String email;

    @Size(min = 3, message = "Password should not be less than 3")
    private String password;

    @Temporal(TemporalType.TIMESTAMP)
    @CreationTimestamp
    private Date createdAt;

    @Column(unique = true)
    @NotNull
    private String token;

    public void setHashedPassword(String password) {
        this.password = new BCryptPasswordEncoder().encode(password);
    }

    public String createToken()
    {
        String token = Usefull.createRandomString(64);

        this.token = token;
        return token;
    }
}
