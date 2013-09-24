#include <assert.h>

#include <SFML/Graphics.hpp>

#include "ParticleGroup.h"
#include "Application.h"
#include "Activity.h"
#include "pEng.h"

int main(int argc, char **argv) {

	pEng::ParticleGroup *pGroup1 = new pEng::ParticleGroup(400);
	pEng::ParticleGroup *pGroup2 = new pEng::ParticleGroup(400);
	pEng::ParticleGroup *pGroup3 = new pEng::ParticleGroup(500);

	pGroup1->addModifier(new pEng::Gravitron(pEng::Point(core::instance().vidMode.width/6, core::instance().vidMode.height/2), 10));
	pGroup1->addModifier(new pEng::RandomColor(pEng::Point(0, 255), pEng::Point(0, 255), pEng::Point(0, 255), pEng::Point(100, 200)));
	pGroup1->addModifier(new pEng::RandomPosition(pEng::Point(core::instance().vidMode.width/6, core::instance().vidMode.height/2), pEng::Point(core::instance().vidMode.width/6, core::instance().vidMode.height/2)));
	pGroup1->addModifier(new pEng::RandomVelocity(pEng::Point(1, 9), pEng::Point(0, 360)));
	pGroup1->addModifier(new pEng::RandomLife(1, 1));
	pGroup1->addModifier(new pEng::RandomSize(1, 1));
	pGroup1->addModifier(new pEng::BoundingBox(pEng::Point(0, 0),  pEng::Point(core::instance().vidMode.width/3, core::instance().vidMode.height), 0.5));
	pGroup1->addModifier(new pEng::Sparkle(10));

	pGroup1->addModifier(new pEng::Mover());


	pGroup1->addRenderer(new pEng::VelocityRenderer());

	pGroup2->addModifier(new pEng::RandomColor(pEng::Point(0, 255), pEng::Point(0, 255), pEng::Point(0, 255), pEng::Point(255, 255)));
	pGroup2->addModifier(new pEng::RandomPosition(pEng::Point(core::instance().vidMode.width/2, core::instance().vidMode.height/2), pEng::Point(core::instance().vidMode.width/2, core::instance().vidMode.height/2)));
	pGroup2->addModifier(new pEng::RandomVelocity(pEng::Point(1, 8), pEng::Point(0, 360)));
	pGroup2->addModifier(new pEng::RandomLife(1, 1));
	pGroup2->addModifier(new pEng::RandomSize(1, 3));
	pGroup2->addModifier(new pEng::BoundingBox(pEng::Point(core::instance().vidMode.width/3, 0),  pEng::Point(core::instance().vidMode.width*2/3, core::instance().vidMode.height), 0.7));
	pGroup2->addModifier(new pEng::Accelerator(-0.2, 270));
	pGroup2->addModifier(new pEng::RandomExpansionRate(-0.01, -0.005));
	pGroup2->addModifier(new pEng::RandomAngle(0, 360));
	pGroup2->addModifier(new pEng::RandomRotation(0, 10));
	
	pGroup2->addModifier(new pEng::Mover());
	pGroup2->addModifier(new pEng::Expander());
	pGroup2->addModifier(new pEng::Rotater());

	pGroup2->addRenderer(new pEng::BasicRenderer());

	pGroup3->addModifier(new pEng::RandomColor(pEng::Point(0, 255), pEng::Point(0, 255), pEng::Point(0, 255), pEng::Point(255, 255)));
	pGroup3->addModifier(new pEng::RandomPosition(pEng::Point(core::instance().vidMode.width*2/3, 0), pEng::Point(core::instance().vidMode.width, 0)));
	pGroup3->addModifier(new pEng::RandomLife(1, 1));
	pGroup3->addModifier(new pEng::RandomSize(1, 1));
	pGroup3->addModifier(new pEng::BoundingBox(pEng::Point(core::instance().vidMode.width*2/3, 0),  pEng::Point(core::instance().vidMode.width, core::instance().vidMode.height), 0.3));
	pGroup3->addModifier(new pEng::Accelerator(-0.3, 270));
	pGroup3->addModifier(new pEng::RandomExpansionRate(-0.01, -0.005));
	
	pGroup3->addModifier(new pEng::Mover());
	pGroup3->addModifier(new pEng::Expander());

	pGroup3->addRenderer(new pEng::VelocityRenderer());

	core::instance().particleManager.addParticleGroup(pGroup1);
	core::instance().particleManager.addParticleGroup(pGroup2);
	core::instance().particleManager.addParticleGroup(pGroup3);

	Activity renderLoop;
	renderLoop.start();

	return 0;
}