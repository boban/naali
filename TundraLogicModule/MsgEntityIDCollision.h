#pragma once

#include "clb/Network/DataDeserializer.h"
#include "clb/Network/DataSerializer.h"

struct MsgEntityIDCollision
{
	MsgEntityIDCollision()
	{
		InitToDefault();
	}

	MsgEntityIDCollision(const char *data, size_t numBytes)
	{
		InitToDefault();
		DataDeserializer dd(data, numBytes);
		DeserializeFrom(dd);
	}

	void InitToDefault()
	{
		reliable = true;
		inOrder = false;
		priority = 100;
	}

	static inline u32 MessageID() { return 114; }
	static inline const char *Name() { return "EntityIDCollision"; }

	bool reliable;
	bool inOrder;
	u32 priority;

	u32 oldEntityID;
	u32 newEntityID;

	inline size_t Size() const
	{
		return 4 + 4;
	}

	inline void SerializeTo(DataSerializer &dst) const
	{
		dst.Add<u32>(oldEntityID);
		dst.Add<u32>(newEntityID);
	}

	inline void DeserializeFrom(DataDeserializer &src)
	{
		oldEntityID = src.Read<u32>();
		newEntityID = src.Read<u32>();
	}

};
