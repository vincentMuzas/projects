package com.dashboard.model;

import com.sun.istack.NotNull;
import lombok.Data;
import org.hibernate.annotations.CreationTimestamp;

import javax.persistence.*;
import java.util.Date;

@Data
@Entity
@Table(name = "widgets")
public class Widget {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;

    @NotNull
    private String serviceName;

    @NotNull
    private String name;

    @NotNull
    private String params;

    @NotNull
    private Long userId;

    @Temporal(TemporalType.TIMESTAMP)
    @CreationTimestamp
    private Date createdAt;
}
