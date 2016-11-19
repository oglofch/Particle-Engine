#include "ParticleManager.h"
#include "Application.h"
#include <iostream>

ParticleManager::ParticleManager() {
	m_particle_groups.reserve(100);
	m_new_groups.reserve(100);
	m_pool.reserve(100);
	for (int i = 0; i < 100; ++i) {
		m_pool.push_back(new pEng::ParticleGroup());
	}
}

ParticleManager::~ParticleManager() {
	std::vector<pEng::ParticleGroup*>::iterator i = m_particle_groups.begin();
	while (i != m_particle_groups.end()) {

		delete (*i);
		++i;
	}
	i = m_new_groups.begin();
	while (i != m_new_groups.end()) {
		pEng::ParticleGroup *group = (*i);

		delete (*i);
		++i;
	}
	i = m_pool.begin();
	while (i != m_pool.end()) {
		pEng::ParticleGroup *group = (*i);

		delete (*i);
		++i;
	}
}

void ParticleManager::update() {
	std::vector<pEng::ParticleGroup*>::iterator i = m_particle_groups.begin();
	while (i != m_particle_groups.end()) {
		if ((*i)->isAlive()) {
			(*i)->update(1/60);
			++i;
		} else {
			m_pool.push_back(*i);
			i = m_particle_groups.erase(i);
		}
	}
	// Copy over new particle groups created in step
	if (!m_new_groups.empty()) {
		std::vector<pEng::ParticleGroup*>::iterator i = m_new_groups.begin();
		while (i != m_new_groups.end()) {
			m_particle_groups.push_back((*i));
			if ((*i)->hasPhysics()) {
				(*i)->createParticleBodies();
			}
			++i;
		}
		m_new_groups.clear();
	}
}

void ParticleManager::render() {
	std::vector<pEng::ParticleGroup*>::iterator i = m_particle_groups.begin();
	while (i != m_particle_groups.end()) {
		(*i)->render(core::instance().window);
		++i;
	}
}

void ParticleManager::addParticleGroup(pEng::ParticleGroup *particleGroup) {
	if (particleGroup != NULL) {
		m_new_groups.push_back(particleGroup);
	}
}

void ParticleManager::clearGroups() {
	std::vector<pEng::ParticleGroup*>::iterator i = m_particle_groups.begin();
	while (i != m_particle_groups.end()) {
		pEng::ParticleGroup *group = (*i);
		if (group->hasPhysics()) {
			group->clearBodies();
		}

		delete (*i);
		++i;
	}
	i = m_new_groups.begin();
	while (i != m_new_groups.end()) {
		pEng::ParticleGroup *group = (*i);

		delete (*i);
		++i;
	}
	m_particle_groups.clear();
	m_new_groups.clear();
}

pEng::ParticleGroup *ParticleManager::getParticleGroup(int capacity) {
	pEng::ParticleGroup *group;

	if (m_pool.size() > 0) {
		group = *(m_pool.end() - 1);
		group->reset(capacity);
		m_pool.erase(m_pool.end() - 1);
	} else {
		group = new pEng::ParticleGroup(capacity);
	}

	return group;
}
