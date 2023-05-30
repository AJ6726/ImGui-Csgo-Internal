#pragma once


struct Vector2
{
	float x, y; 

	Vector2 operator +	(Vector2 vec2) { return { x + vec2.x, y + vec2.y }; }
	Vector2 operator -	(Vector2 vec2) { return { x - vec2.x, y - vec2.y }; }
	Vector2 operator +=	(float scale) { return { x += scale, y += scale }; }
	Vector2 operator -=	(float scale) { return { x -= scale, y -= scale }; }

	Vector2 operator *	(Vector2 vec2) { return { x * vec2.x, y * vec2.y }; }
	Vector2 operator /	(Vector2 vec2) { return { x / vec2.x, y / vec2.y }; }
	Vector2 operator *=	(float scale) { return { x *= scale, y *= scale }; }
	Vector2 operator /=	(float scale) { return { x /= scale, y /= scale }; }

};

struct Vector3
{
	float x, y, z;

	Vector3 operator +	(Vector3 vec3) { return { x + vec3.x, y + vec3.y, z + vec3.z }; }
	Vector3 operator -	(Vector3 vec3) { return { x - vec3.x, y - vec3.y, z - vec3.z }; }
	Vector3 operator +=	(Vector3 vec3) { return { x += vec3.x, y += vec3.y, z += vec3.z }; }
	Vector3 operator -=	(Vector3 vec3) { return { x -= vec3.x, y -= vec3.y, z -= vec3.z }; }
	Vector3 operator +=	(float scale) { return { x += scale, y += scale, z += scale }; }
	Vector3 operator -=	(float scale) { return { x -= scale, y -= scale, z -= scale }; }

	Vector3 operator * 	(Vector3 vec3) { return { x * vec3.x, y * vec3.y, z * vec3.z }; }
	Vector3 operator /	(Vector3 vec3)
	{
		if(vec3.z == 0.f)
			return { x / vec3.x, y / vec3.y, z};

		return { x / vec3.x, y / vec3.y, z / vec3.z};
	}

	Vector3 operator /	(float scale) { return { x / scale, y / scale, z / scale }; }

	Vector3 operator *=	(float scale) { return { x *= scale, y *= scale, z *= scale }; }
	Vector3 operator /=	(float scale) { return { x /= scale, y /= scale, z /= scale }; }

};

struct Vector4
{
	float x, y, z, w; 

	Vector4 operator -	(Vector4 vec4) { return { x - vec4.x, y - vec4.y, z - vec4.z, w - vec4.w }; }
};
