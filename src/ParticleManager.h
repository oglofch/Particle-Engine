#ifndef _PARTICLE_MANAGER_H_
#define _PARTICLE_MANAGER_H_

#include "pEng.h"

class ParticleManager 
{
private:
	std::vector<pEng::ParticleGroup*> m_particle_groups;
	std::vector<pEng::ParticleGroup*> m_new_groups;

	std::vector<pEng::ParticleGroup*> m_pool;

public:
	ParticleManager();
	~ParticleManager();

	void update();
	void render();

	void addParticleGroup(pEng::ParticleGroup *particleGroup);

	void clearGroups();

	pEng::ParticleGroup *getParticleGroup(int capacity);
};

#endif