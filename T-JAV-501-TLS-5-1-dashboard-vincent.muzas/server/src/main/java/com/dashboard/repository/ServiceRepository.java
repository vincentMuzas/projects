package com.dashboard.repository;

import com.dashboard.model.Service;
import org.springframework.data.repository.CrudRepository;
import org.springframework.stereotype.Repository;

import java.util.Optional;

@Repository
public interface ServiceRepository extends CrudRepository<Service, Long> {
    Iterable<Service> findByUserId(final Long user_id);
    Optional<Service> findByNameAndUserId(final String name, final Long userId);
}