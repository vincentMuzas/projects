package com.dashboard.repository;

import com.dashboard.model.Widget;
import org.springframework.data.repository.CrudRepository;
import org.springframework.stereotype.Repository;

import java.util.Optional;

@Repository
public interface WidgetRepository extends CrudRepository<Widget, Long> {
    Iterable<Widget> findByUserId(final Long user_id);
}