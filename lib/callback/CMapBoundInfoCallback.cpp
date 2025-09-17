/*
 * CMapBoundInfoCallback.cpp, part of VCMI engine
 *
 * Authors: listed in file AUTHORS in main folder
 *
 * License: GNU General Public License v2.0 or later
 * Full text of license available in license.txt file, in main folder
 *
 */
#include "StdInc.h"
#include "CMapBoundInfoCallback.h"
#include "../lib/mapping/CMap.h"

#define THROW_EDITOR_UNSUPPORTED \
	throw std::runtime_error(std::string("EditorCallback: ") + __func__ + " is not available in map editor")

VCMI_LIB_NAMESPACE_BEGIN

const CMap * CMapBoundInfoCallback::getMapConstPtr() const
{
	if(!map)
		throw std::runtime_error("EditorCallback: map pointer is null");
	return map;
}

CMapBoundInfoCallback::CMapBoundInfoCallback(const CMap * map)
	: map(map)
{}

void CMapBoundInfoCallback::setMap(const CMap * newMap)
{
	map = newMap;
}

CGameState & CMapBoundInfoCallback::gameState()
{
	THROW_EDITOR_UNSUPPORTED;
}

const CGameState & CMapBoundInfoCallback::gameState() const
{
	THROW_EDITOR_UNSUPPORTED;
}

const StartInfo * CMapBoundInfoCallback::getStartInfo() const
{
	THROW_EDITOR_UNSUPPORTED;
}

int CMapBoundInfoCallback::getDate(Date mode) const
{
	THROW_EDITOR_UNSUPPORTED;
}

const TerrainTile * CMapBoundInfoCallback::getTile(int3 tile, bool) const
{
	return &map->getTile(tile);
}

const TerrainTile * CMapBoundInfoCallback::getTileUnchecked(int3) const
{
	THROW_EDITOR_UNSUPPORTED;
}

bool CMapBoundInfoCallback::isTileGuardedUnchecked(int3 tile) const
{
	THROW_EDITOR_UNSUPPORTED;
}

const CGObjectInstance * CMapBoundInfoCallback::getTopObj(int3) const
{
	THROW_EDITOR_UNSUPPORTED;
}

EDiggingStatus CMapBoundInfoCallback::getTileDigStatus(int3, bool) const
{
	THROW_EDITOR_UNSUPPORTED;
}

void CMapBoundInfoCallback::calculatePaths(const std::shared_ptr<PathfinderConfig> &) const
{
	THROW_EDITOR_UNSUPPORTED;
}

int3 CMapBoundInfoCallback::guardingCreaturePosition(int3) const
{
	THROW_EDITOR_UNSUPPORTED;
}

bool CMapBoundInfoCallback::checkForVisitableDir(const int3 &, const int3 &) const
{
	THROW_EDITOR_UNSUPPORTED;
}

std::vector<const CGObjectInstance*> CMapBoundInfoCallback::getGuardingCreatures(int3) const
{
	THROW_EDITOR_UNSUPPORTED;
}

void CMapBoundInfoCallback::getTilesInRange(FowTilesType &, const int3 &, int, ETileVisibility, std::optional<PlayerColor>, int3::EDistanceFormula) const
{
	THROW_EDITOR_UNSUPPORTED;
}

void CMapBoundInfoCallback::getAllTiles(FowTilesType &, std::optional<PlayerColor>, int, const std::function<bool(const TerrainTile *)> &) const
{
	THROW_EDITOR_UNSUPPORTED;
}

std::vector<ObjectInstanceID> CMapBoundInfoCallback::getVisibleTeleportObjects(std::vector<ObjectInstanceID>, PlayerColor) const
{
	THROW_EDITOR_UNSUPPORTED;
}

std::vector<ObjectInstanceID> CMapBoundInfoCallback::getTeleportChannelEntrances(TeleportChannelID, PlayerColor) const
{
	THROW_EDITOR_UNSUPPORTED;
}

std::vector<ObjectInstanceID> CMapBoundInfoCallback::getTeleportChannelExits(TeleportChannelID, PlayerColor) const
{
	THROW_EDITOR_UNSUPPORTED;
}

bool CMapBoundInfoCallback::isTeleportChannelImpassable(TeleportChannelID, PlayerColor) const
{
	THROW_EDITOR_UNSUPPORTED;
}

bool CMapBoundInfoCallback::isTeleportChannelBidirectional(TeleportChannelID, PlayerColor) const
{
	THROW_EDITOR_UNSUPPORTED;
}

bool CMapBoundInfoCallback::isTeleportChannelUnidirectional(TeleportChannelID, PlayerColor) const
{
	THROW_EDITOR_UNSUPPORTED;
}

bool CMapBoundInfoCallback::isTeleportEntrancePassable(const CGTeleport *, PlayerColor) const
{
	THROW_EDITOR_UNSUPPORTED;
}

bool CMapBoundInfoCallback::isVisibleFor(int3 pos, PlayerColor player) const
{
	THROW_EDITOR_UNSUPPORTED;
}

bool CMapBoundInfoCallback::isVisibleFor(const CGObjectInstance *obj, PlayerColor player) const
{
	THROW_EDITOR_UNSUPPORTED;
}

#if SCRIPTING_ENABLED
scripting::Pool * EditorCallback::getGlobalContextPool() const
{
	THROW_EDITOR_UNSUPPORTED;
}
#endif

const TeamState * CMapBoundInfoCallback::getTeam(TeamID) const
{
	THROW_EDITOR_UNSUPPORTED;
}

const TeamState * CMapBoundInfoCallback::getPlayerTeam(PlayerColor) const
{
	THROW_EDITOR_UNSUPPORTED;
}

const PlayerState * CMapBoundInfoCallback::getPlayerState(PlayerColor, bool) const
{
	THROW_EDITOR_UNSUPPORTED;
}

const PlayerSettings * CMapBoundInfoCallback::getPlayerSettings(PlayerColor) const
{
	THROW_EDITOR_UNSUPPORTED;
}

PlayerRelations CMapBoundInfoCallback::getPlayerRelations(PlayerColor, PlayerColor) const
{
	THROW_EDITOR_UNSUPPORTED;
}

int CMapBoundInfoCallback::getHeroCount(PlayerColor, bool) const
{
	THROW_EDITOR_UNSUPPORTED;
}

EPlayerStatus CMapBoundInfoCallback::getPlayerStatus(PlayerColor, bool) const
{
	THROW_EDITOR_UNSUPPORTED;
}

int CMapBoundInfoCallback::getResource(PlayerColor, GameResID) const
{
	THROW_EDITOR_UNSUPPORTED;
}

VCMI_LIB_NAMESPACE_END
