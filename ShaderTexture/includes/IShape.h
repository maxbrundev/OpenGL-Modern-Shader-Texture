#pragma once

namespace Shape
{
	class IShape
	{
	public:
		virtual ~IShape() = default;
	private:
		virtual void InitShape() = 0;
		virtual void DrawShape() = 0;
	};
}