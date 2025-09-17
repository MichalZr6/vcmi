/*
 * IMapInfoCallback.cpp, part of VCMI engine
 *
 * Authors: listed in file AUTHORS in main folder
 *
 * License: GNU General Public License v2.0 or later
 * Full text of license available in license.txt file, in main folder
 *
 */
#include "StdInc.h"
#include "IMapInfoCallback.h"
#include "../constants/EntityIdentifiers.h"
#include "../mapObjects/CGObjectInstance.h"
#include "../mapObjects/CGHeroInstance.h"
#include "../mapObjects/CGTownInstance.h"
#include "../mapObjects/MiscObjects.h"
#include "../StartInfo.h"
#include "../mapping/CMap.h"
#include "../spells/CSpellHandler.h"

VCMI_LIB_NAMESPACE_BEGIN

IMapInfoCallback::~IMapInfoCallback() = default;

const CGObjectInstance * IMapInfoCallback::getObj(ObjectInstanceID objid, bool verbose) const
{
	if(!objid.hasValue())
	{
		if(verbose)
			logGlobal->error("Cannot get object with id %d. No such object", objid.getNum());
		return nullptr;
	}

	const CGObjectInstance * ret = getMapConstPtr()->getObject(objid);
	if(!ret && verbose)
	{
		logGlobal->error("Cannot get object with id %d. Object was removed", objid.getNum());
		return nullptr;
	}

	return ret;
}

const CGHeroInstance * IMapInfoCallback::getHero(ObjectInstanceID objid) const
{
	const CGObjectInstance * obj = getObj(objid, false);
	return dynamic_cast<const CGHeroInstance *>(obj);
}

const CGTownInstance * IMapInfoCallback::getTown(ObjectInstanceID objid) const
{
	const CGObjectInstance * obj = getObj(objid, false);
	return dynamic_cast<const CGTownInstance*>(obj);
}

PlayerColor IMapInfoCallback::getOwner(ObjectInstanceID heroID) const
{
	const CGObjectInstance * obj = getObj(heroID);
	if(!obj)
	{
		logGlobal->error("MapInfoCallback::getOwner(heroID): No such object for heroID: %d", heroID.num);
		return PlayerColor::CANNOT_DETERMINE;
	}

	return obj->tempOwner;
}

const CArtifactInstance * IMapInfoCallback::getArtInstance(ArtifactInstanceID aid) const
{
	return getMapConstPtr()->getArtifactInstance(aid);
}

const CGObjectInstance * IMapInfoCallback::getObjInstance(ObjectInstanceID oid) const
{
	return getMapConstPtr()->getObject((oid));
}

bool IMapInfoCallback::isInTheMap(const int3 & pos) const
{
	return getMapConstPtr()->isInTheMap(pos);
}

bool IMapInfoCallback::isAllowed(SpellID id) const
{
	return getMapConstPtr()->allowedSpells.count(id) != 0;
}

bool IMapInfoCallback::isAllowed(ArtifactID id) const
{
	return getMapConstPtr()->allowedArtifact.count(id) != 0;
}

bool IMapInfoCallback::isAllowed(SecondarySkill id) const
{
	return getMapConstPtr()->allowedAbilities.count(id) != 0;
}

int3 IMapInfoCallback::getMapSize() const
{
	return int3(getMapConstPtr()->width, getMapConstPtr()->height, getMapConstPtr()->levels());
}

void IMapInfoCallback::getAllowedSpells(std::vector<SpellID> & out, std::optional<ui16> level)
{
	for (auto const & spellID : getMapConstPtr()->allowedSpells)
	{
		const auto * spell = spellID.toEntity(LIBRARY);

		if (!isAllowed(spellID))
			continue;

		if (level.has_value() && spell->getLevel() != level)
			continue;

		out.push_back(spellID);
	}
}

const IGameSettings & IMapInfoCallback::getSettings() const
{
	return getMapConstPtr()->getSettings();
}

const CMapHeader * IMapInfoCallback::getMapHeader() const
{
	return getMapConstPtr();
}

VCMI_LIB_NAMESPACE_END
