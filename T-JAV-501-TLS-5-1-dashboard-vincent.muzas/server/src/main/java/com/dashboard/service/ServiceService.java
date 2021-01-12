package com.dashboard.service;

import com.dashboard.model.Service;
import com.dashboard.repository.ServiceRepository;
import lombok.Data;
import org.springframework.beans.factory.annotation.Autowired;
import java.util.Optional;

@Data
@org.springframework.stereotype.Service
public class ServiceService {

    @Autowired
    private ServiceRepository serviceRepository;

    public Optional<Service> getService(final Long id) {
        return serviceRepository.findById(id);
    }

    public Iterable<Service> getServices() {
        return serviceRepository.findAll();
    }

    public Iterable<Service> getServicesByUserId(final Long user_id) {
        return serviceRepository.findByUserId(user_id);
    }

    public Optional<Service> getServiceByNameAndUserId(final String name, final Long userId) {
        return serviceRepository.findByNameAndUserId(name, userId);
    }

    public void deleteService(final Long id) {
        serviceRepository.deleteById(id);
    }

    public Service saveService(Service service) {
        return serviceRepository.save(service);
    }
}
