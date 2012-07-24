#ifndef _DRAW_P_HPP_
#define _DRAW_P_HPP_

#include "build_options.h"

#if BUILD_WITH_QT

#include <QGraphicsView>

class QGraphicsScene;

namespace Private
{
	class Draw : public QGraphicsView
	{
	Q_OBJECT
	public:
		Draw();
		~Draw();
		
		bool open();
		void point(const int& x, const int& y);
		void line(const int& sx, const int& sy, const int& ex, const int& ey);
		void clear();
		void setSize(const unsigned int& width, const unsigned int& height);
		void raise();
		void close();
		
		static bool isInited();
		static void init();
	private:
		static bool s_inited;
		QGraphicsScene *m_scene;
	};
}

#else

namespace Private
{
	class Draw
	{
	public:
		Draw() {}
		~Draw() {}
		
		bool open() { return false; }
		void point(const int& x, const int& y) {}
		void line(const int& sx, const int& sy, const int& ex, const int& ey) {}
		void clear() {}
		void setSize(const unsigned int& width, const unsigned int& height) {}
		void raise() {}
		void close() {}
		
		static bool isInited() { return false; }
		static void init() {}
	};
}

#endif

#endif
