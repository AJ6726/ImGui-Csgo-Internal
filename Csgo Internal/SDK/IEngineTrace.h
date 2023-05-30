#pragma once
#include <Interfaces.h>

#define	CONTENTS_SOLID			0x1	
#define CONTENTS_GRATE			0x8
#define CONTENTS_MOVEABLE		0x4000
#define	CONTENTS_MONSTER		0x2000000
#define	CONTENTS_WINDOW			0x2
#define	CONTENTS_DEBRIS			0x4000000
#define CONTENTS_HITBOX			0x40000000
#define TRACEMASK (CONTENTS_HITBOX | CONTENTS_DEBRIS | CONTENTS_MONSTER | CONTENTS_MOVEABLE | CONTENTS_GRATE | CONTENTS_SOLID)

struct Ray;
struct CTraceFilter; 

struct Plane; 
struct Surface;
struct Trace; 


struct IEngineTrace
{
	void TraceRay(const Ray& ray, unsigned int fMask, CTraceFilter* pTraceFilter, Trace* pTrace)
	{
		CallVirtualFunction<void, const Ray&, unsigned int, CTraceFilter*, Trace*>(this, 5, ray, fMask, pTraceFilter, pTrace);
	}
};

struct Ray
{
	Vector3  m_Start;		// starting point, centered within the extent
	char	 pad[4]; 	

	Vector3  m_Delta;		// direction + length of the ray
	char	 pad2[4]; 

	Vector4  m_StartOffset;	// Add this to m_Start to get the actual ray start
	Vector4  m_Extents;		// Describes an axis aligned box extruded along a ray
	const Matrix_3x4* m_pWorldAxisTransform;
	bool	m_IsRay = true;	// are the extents zero?
	bool	m_IsSwept;		// is delta !

	Ray(Vector3& src, Vector3& dst)
	{
		m_Start = src;
		m_Delta = dst - src;
		m_IsSwept = m_Delta.x || m_Delta.y || m_Delta.z;
	}

};

enum TraceType_t
{
	TRACE_EVERYTHING = 0,
	TRACE_WORLD_ONLY,				// NOTE: This does *not* test static props!!!
	TRACE_ENTITIES_ONLY,			// NOTE: This version will *not* test static props
	TRACE_EVERYTHING_FILTER_PROPS,	// NOTE: This version will pass the IHandleEntity for props through the filter, unlike all other filters
};


struct CTraceFilter
{
	CBaseEntity* skip = nullptr;

	CTraceFilter(CBaseEntity* entity)
	{
		skip = entity;
	}

	virtual bool ShouldHitEntity(CBaseEntity* entity, int contentsMask)
	{
		return entity != skip;
	}

	virtual TraceType_t	GetTraceType() const
	{
		return TRACE_EVERYTHING;
	}

};

struct Plane
{
	Vector3	normal;
	float	dist;
	char	type;			// for fast side tests
	char	signbits;		// signx + (signy<<1) + (signz<<1)
	char	pad[2];
};


struct Surface
{
	const char* name;
	short		surfaceProps;
	unsigned short	flags;
};

struct Trace
{

	// these members are aligned!!
	Vector3			startpos;				// start position
	Vector3			endpos;					// final position
	Plane			plane; 					// surface normal at impact

	float			fraction;				// time completed, 1.0 = didn't hit anything

	int				contents;				// contents on other side of surface hit
	unsigned short	dispFlags;				// displacement flags for marking surfaces with data

	bool			allsolid;				// if true, plane is not valid
	bool			startsolid;				// if true, the initial point was in a solid area

	float			fractionleftsolid;		// time we left a solid, only valid if we started in solid
	Surface			surface;

	int				hitgroup;

	short			physicsbone;		// physics bone hit by trace in studio
	unsigned short	worldSurfaceIndex;	// Index of the msurface2_t, if applicable

	CBaseEntity* entity;

}; 