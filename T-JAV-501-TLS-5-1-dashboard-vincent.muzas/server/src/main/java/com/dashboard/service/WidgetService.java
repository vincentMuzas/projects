package com.dashboard.service;

import com.dashboard.model.Widget;
import com.dashboard.repository.WidgetRepository;
import lombok.Data;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.Optional;

@Data
@Service
public class WidgetService {

    @Autowired
    private WidgetRepository widgetRepository;

    public Optional<Widget> getWidget(final Long id) {
        return widgetRepository.findById(id);
    }

    public Iterable<Widget> getWidgets() {
        return widgetRepository.findAll();
    }

    public Iterable<Widget> getWidgetsByUserId(final Long user_id) {
        return widgetRepository.findByUserId(user_id);
    }

    public void deleteWidget(final Long id) {
        widgetRepository.deleteById(id);
    }

    public Widget saveWidget(Widget widget) {
        return widgetRepository.save(widget);
    }
}
