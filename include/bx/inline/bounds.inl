/*
 * Copyright 2011-2025 Branimir Karadzic. All rights reserved.
 * License: https://github.com/bkaradzic/bgfx#license-bsd-2-clause
 */

#ifndef BX_BOUNDS_H_HEADER_GUARD
#	error "Must be included from bounds.h!"
#endif // BX_BOUNDS_H_HEADER_GUARD

namespace bx
{
	inline Interval::Interval(float _val)
		: min(_val)
		, max(_val)
	{
	}

	inline Interval::Interval(float _min, float _max)
		: min(_min)
		, max(_max)
	{
	}

	inline void Interval::set(float _val)
	{
		min = _val;
		max = _val;
	}

	inline void Interval::setCenter(float _val)
	{
		const float extents = (max - min) * 0.5f;
		min = _val - extents;
		max = _val + extents;
	}

	inline void Interval::expand(float _val)
	{
		min = bx::min(min, _val);
		max = bx::max(max, _val);
	}

	inline Vec3 getPointAt(const Ray& _ray, float _t)
	{
		return mad(_ray.dir, _t, _ray.pos);
	}

	inline Vec3 getPointAt(const Line& _line, float _t)
	{
		return mad(_line.dir, _t, _line.pos);
	}

	inline Vec3 getPointAt(const LineSegment& _line, float _t)
	{
		return lerp(_line.pos, _line.end, _t);
	}

	inline bool intersect(const Ray& _ray, const Plane& _plane, Hit* _hit)
	{
		return intersect(_ray, _plane, false, _hit);
	}

	inline bool overlap(const Interval& _interval, float _t)
	{
		return _t > _interval.min
			&& _t < _interval.max
			;
	}

	inline bool overlap(const Interval& _intervalA, const Interval& _intervalB)
	{
		return _intervalA.max > _intervalB.min
			&& _intervalB.max > _intervalA.min
			;
	}

	inline bool overlap(const Aabb& _aabb, const Sphere& _sphere)
	{
		return overlap(_sphere, _aabb);
	}

	inline bool overlap(const Aabb& _aabb, const Cylinder& _cylinder)
	{
		return overlap(_cylinder, _aabb);
	}

	inline bool overlap(const Capsule& _capsule, const Sphere& _sphere)
	{
		return overlap(_sphere, _capsule);
	}

	inline bool overlap(const Capsule& _capsule, const Aabb& _aabb)
	{
		return overlap(_aabb, _capsule);
	}

	inline bool overlap(const Capsule& _capsule, const Triangle& _triangle)
	{
		return overlap(_triangle, _capsule);
	}

	inline bool overlap(const Capsule& _capsule, const Cone& _cone)
	{
		return overlap(_cone, _capsule);
	}

	inline bool overlap(const Capsule& _capsule, const Cylinder& _cylinder)
	{
		return overlap(_cylinder, _capsule);
	}

	inline bool overlap(const Capsule& _capsule, const Disk& _disk)
	{
		return overlap(_disk, _capsule);
	}

	inline bool overlap(const Capsule& _capsule, const Obb& _obb)
	{
		return overlap(_obb, _capsule);
	}

	inline bool overlap(const Cone& _cone, const Sphere& _sphere)
	{
		return overlap(_sphere, _cone);
	}

	inline bool overlap(const Cone& _cone, const Aabb& _aabb)
	{
		return overlap(_aabb, _cone);
	}

	inline bool overlap(const Cone& _cone, const Plane& _plane)
	{
		return overlap(_plane, _cone);
	}

	inline bool overlap(const Cone& _cone, const Triangle& _triangle)
	{
		return overlap(_triangle, _cone);
	}

	inline bool overlap(const Cylinder& _cylinder, const Triangle& _triangle)
	{
		return overlap(_triangle, _cylinder);
	}

	inline bool overlap(const Cylinder& _cylinder, const Cone& _cone)
	{
		return overlap(_cone, _cylinder);
	}

	inline bool overlap(const Disk& _disk, const Sphere& _sphere)
	{
		return overlap(_sphere, _disk);
	}

	inline bool overlap(const Disk& _disk, const Aabb& _aabb)
	{
		return overlap(_aabb, _disk);
	}

	inline bool overlap(const Disk& _disk, const Triangle& _triangle)
	{
		return overlap(_triangle, _disk);
	}

	inline bool overlap(const Disk& _disk, const Cylinder& _cylinder)
	{
		return overlap(_cylinder, _disk);
	}

	inline bool overlap(const Disk& _disk, const Cone& _cone)
	{
		return overlap(_cone, _disk);
	}

	inline bool overlap(const Obb& _obb, const Sphere& _sphere)
	{
		return overlap(_sphere, _obb);
	}

	inline bool overlap(const Obb& _obb, const Aabb& _aabb)
	{
		return overlap(_aabb, _obb);
	}

	inline bool overlap(const Obb& _obb, const Triangle& _triangle)
	{
		return overlap(_triangle, _obb);
	}

	inline bool overlap(const Obb& _obb, const Cylinder& _cylinder)
	{
		return overlap(_cylinder, _obb);
	}

	inline bool overlap(const Obb& _obb, const Cone& _cone)
	{
		return overlap(_cone, _obb);
	}

	inline bool overlap(const Obb& _obb, const Disk& _disk)
	{
		return overlap(_disk, _obb);
	}

	inline bool overlap(const Plane& _plane, const Sphere& _sphere)
	{
		return overlap(_sphere, _plane);
	}

	inline bool overlap(const Plane& _plane, const Aabb& _aabb)
	{
		return overlap(_aabb, _plane);
	}

	inline bool overlap(const Plane& _plane, const Triangle& _triangle)
	{
		return overlap(_triangle, _plane);
	}

	inline bool overlap(const Plane& _plane, const Cylinder& _cylinder)
	{
		return overlap(_cylinder, _plane);
	}

	inline bool overlap(const Plane& _plane, const Capsule& _capsule)
	{
		return overlap(_capsule, _plane);
	}

	inline bool overlap(const Plane& _plane, const Disk& _disk)
	{
		return overlap(_disk, _plane);
	}

	inline bool overlap(const Plane& _plane, const Obb& _obb)
	{
		return overlap(_obb, _plane);
	}

	inline bool overlap(const Sphere& _sphere, const Cylinder& _cylinder)
	{
		return overlap(_cylinder, _sphere);
	}

	inline bool overlap(const Triangle& _triangle, const Sphere& _sphere)
	{
		return overlap(_sphere, _triangle);
	}

	inline bool overlap(const Triangle& _triangle, const Aabb& _aabb)
	{
		return overlap(_aabb, _triangle);
	}

} // namespace bx
