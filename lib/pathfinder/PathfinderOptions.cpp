/*
 * CPathfinder.cpp, part of VCMI engine
 *
 * Authors: listed in file AUTHORS in main folder
 *
 * License: GNU General Public License v2.0 or later
 * Full text of license available in license.txt file, in main folder
 *
 */
#include "StdInc.h"
#include "PathfinderOptions.h"

#include "../GameSettings.h"
#include "../VCMI_Lib.h"
#include "NodeStorage.h"
#include "PathfindingRules.h"
#include "CPathfinder.h"
#include "mapObjects/CGHeroInstance.h"

VCMI_LIB_NAMESPACE_BEGIN

PathfinderOptions::PathfinderOptions()
	: useFlying(true)
	, useWaterWalking(true)
	, ignoreGuards(VLC->settings()->getBoolean(EGameSettings::PATHFINDER_IGNORE_GUARDS))
	, useEmbarkAndDisembark(VLC->settings()->getBoolean(EGameSettings::PATHFINDER_USE_BOAT))
	, useTeleportTwoWay(VLC->settings()->getBoolean(EGameSettings::PATHFINDER_USE_MONOLITH_TWO_WAY))
	, useTeleportOneWay(VLC->settings()->getBoolean(EGameSettings::PATHFINDER_USE_MONOLITH_ONE_WAY_UNIQUE))
	, useTeleportOneWayRandom(VLC->settings()->getBoolean(EGameSettings::PATHFINDER_USE_MONOLITH_ONE_WAY_RANDOM))
	, useTeleportWhirlpool(VLC->settings()->getBoolean(EGameSettings::PATHFINDER_USE_WHIRLPOOL))
	, originalFlyRules(VLC->settings()->getBoolean(EGameSettings::PATHFINDER_ORIGINAL_FLY_RULES))
	, useCastleGate(false)
	, lightweightFlyingMode(false)
	, oneTurnSpecialLayersLimit(true)
	, turnLimit(std::numeric_limits<uint8_t>::max())
	, canUseCast(false)
	, allowLayerTransitioningAfterBattle(false)
	, forceUseTeleportWhirlpool(false)
{
}

PathfinderConfig::PathfinderConfig(std::shared_ptr<INodeStorage> nodeStorage, std::vector<std::shared_ptr<IPathfindingRule>> rules):
	nodeStorage(std::move(nodeStorage)),
	rules(std::move(rules))
{
}

void PathfinderConfig::checkIfTownlessAndAllowOneWayTeleports(const CGHeroInstance * hero)
{
	// FIXME: should be enabled by default with some bigger AI refactor so that main heroes are strong enough to
	// go through and/or enable scouts (at some point ?) to visit such monoliths
	// see first TODO in the top of PathfinderOptions.h
	if (hero->cb->howManyTowns(hero->getOwner()) == 0)
	{
		options.useTeleportOneWay = true;
		options.useTeleportOneWayRandom = true;
	}
}

std::vector<std::shared_ptr<IPathfindingRule>> SingleHeroPathfinderConfig::buildRuleSet()
{
	return std::vector<std::shared_ptr<IPathfindingRule>>{
		std::make_shared<LayerTransitionRule>(),
			std::make_shared<DestinationActionRule>(),
			std::make_shared<MovementToDestinationRule>(),
			std::make_shared<MovementCostRule>(),
			std::make_shared<MovementAfterDestinationRule>()
	};
}

SingleHeroPathfinderConfig::~SingleHeroPathfinderConfig() = default;

SingleHeroPathfinderConfig::SingleHeroPathfinderConfig(CPathsInfo & out, CGameState * gs, const CGHeroInstance * hero)
	: PathfinderConfig(std::make_shared<NodeStorage>(out, hero), buildRuleSet())
{
	checkIfTownlessAndAllowOneWayTeleports(hero);
	pathfinderHelper = std::make_unique<CPathfinderHelper>(gs, hero, options);
}

CPathfinderHelper * SingleHeroPathfinderConfig::getOrCreatePathfinderHelper(const PathNodeInfo & source, CGameState * gs)
{
	return pathfinderHelper.get();
}

VCMI_LIB_NAMESPACE_END
