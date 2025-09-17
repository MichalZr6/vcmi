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

#define THROW_UNSUPPORTED \
	throw std::runtime_error(std::string("CMapBoundInfoCallback: ") + __func__ + " is not available.")

VCMI_LIB_NAMESPACE_BEGIN

CMapBoundInfoCallback::CMapBoundInfoCallback(CMap * map)
	: boundMap(map)
{}

void CMapBoundInfoCallback::setMap(CMap * newMap)
{
	boundMap = newMap;
}

CMap & CMapBoundInfoCallback::map()
{
	if(boundMap)
		return *boundMap;

	throw std::runtime_error("CMapBoundInfoCallback: no map available");
}

const CMap & CMapBoundInfoCallback::map() const
{
	if(boundMap)
		return *boundMap;

	throw std::runtime_error("CMapBoundInfoCallback: no map available");
}

CGameState & CMapBoundInfoCallback::gameState()
{
	THROW_UNSUPPORTED;
}

const CGameState & CMapBoundInfoCallback::gameState() const
{
	THROW_UNSUPPORTED;
}

const StartInfo * CMapBoundInfoCallback::getStartInfo() const
{
	THROW_UNSUPPORTED;
}

int CMapBoundInfoCallback::getDate(Date mode) const
{
	THROW_UNSUPPORTED;
}

const TerrainTile * CMapBoundInfoCallback::getTile(int3 tile, bool) const
{
	return &boundMap->getTile(tile);
}

const TerrainTile * CMapBoundInfoCallback::getTileUnchecked(int3) const
{
	THROW_UNSUPPORTED;
}

bool CMapBoundInfoCallback::isTileGuardedUnchecked(int3 tile) const
{
	THROW_UNSUPPORTED;
}

const CGObjectInstance * CMapBoundInfoCallback::getTopObj(int3) const
{
	THROW_UNSUPPORTED;
}

EDiggingStatus CMapBoundInfoCallback::getTileDigStatus(int3, bool) const
{
	THROW_UNSUPPORTED;
}

void CMapBoundInfoCallback::calculatePaths(const std::shared_ptr<PathfinderConfig> &) const
{
	THROW_UNSUPPORTED;
}

int3 CMapBoundInfoCallback::guardingCreaturePosition(int3) const
{
	THROW_UNSUPPORTED;
}

bool CMapBoundInfoCallback::checkForVisitableDir(const int3 &, const int3 &) const
{
	THROW_UNSUPPORTED;
}

std::vector<const CGObjectInstance*> CMapBoundInfoCallback::getGuardingCreatures(int3) const
{
	THROW_UNSUPPORTED;
}

void CMapBoundInfoCallback::getTilesInRange(FowTilesType &, const int3 &, int, ETileVisibility, std::optional<PlayerColor>, int3::EDistanceFormula) const
{
	THROW_UNSUPPORTED;
}

void CMapBoundInfoCallback::getAllTiles(FowTilesType &, std::optional<PlayerColor>, int, const std::function<bool(const TerrainTile *)> &) const
{
	THROW_UNSUPPORTED;
}

std::vector<ObjectInstanceID> CMapBoundInfoCallback::getVisibleTeleportObjects(std::vector<ObjectInstanceID>, PlayerColor) const
{
	THROW_UNSUPPORTED;
}

std::vector<ObjectInstanceID> CMapBoundInfoCallback::getTeleportChannelEntrances(TeleportChannelID, PlayerColor) const
{
	THROW_UNSUPPORTED;
}

std::vector<ObjectInstanceID> CMapBoundInfoCallback::getTeleportChannelExits(TeleportChannelID, PlayerColor) const
{
	THROW_UNSUPPORTED;
}

bool CMapBoundInfoCallback::isTeleportChannelImpassable(TeleportChannelID, PlayerColor) const
{
	THROW_UNSUPPORTED;
}

bool CMapBoundInfoCallback::isTeleportChannelBidirectional(TeleportChannelID, PlayerColor) const
{
	THROW_UNSUPPORTED;
}

bool CMapBoundInfoCallback::isTeleportChannelUnidirectional(TeleportChannelID, PlayerColor) const
{
	THROW_UNSUPPORTED;
}

bool CMapBoundInfoCallback::isTeleportEntrancePassable(const CGTeleport *, PlayerColor) const
{
	THROW_UNSUPPORTED;
}

bool CMapBoundInfoCallback::isVisibleFor(int3 pos, PlayerColor player) const
{
	THROW_UNSUPPORTED;
}

bool CMapBoundInfoCallback::isVisibleFor(const CGObjectInstance *obj, PlayerColor player) const
{
	THROW_UNSUPPORTED;
}

#if SCRIPTING_ENABLED
scripting::Pool * EditorCallback::getGlobalContextPool() const
{
	THROW_UNSUPPORTED;
}
#endif

const TeamState * CMapBoundInfoCallback::getTeam(TeamID) const
{
	THROW_UNSUPPORTED;
}

const TeamState * CMapBoundInfoCallback::getPlayerTeam(PlayerColor) const
{
	THROW_UNSUPPORTED;
}

const PlayerState * CMapBoundInfoCallback::getPlayerState(PlayerColor, bool) const
{
	THROW_UNSUPPORTED;
}

const PlayerSettings * CMapBoundInfoCallback::getPlayerSettings(PlayerColor) const
{
	THROW_UNSUPPORTED;
}

PlayerRelations CMapBoundInfoCallback::getPlayerRelations(PlayerColor, PlayerColor) const
{
	THROW_UNSUPPORTED;
}

int CMapBoundInfoCallback::getHeroCount(PlayerColor, bool) const
{
	THROW_UNSUPPORTED;
}

EPlayerStatus CMapBoundInfoCallback::getPlayerStatus(PlayerColor, bool) const
{
	THROW_UNSUPPORTED;
}

int CMapBoundInfoCallback::getResource(PlayerColor, GameResID) const
{
	THROW_UNSUPPORTED;
}

VCMI_LIB_NAMESPACE_END
