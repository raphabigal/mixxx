#ifndef SCRIPT_LUAINTERFACE_H
#define SCRIPT_LUAINTERFACE_H

extern "C" {
	#include <lua.h>
	#include <lauxlib.h>
	#include <lualib.h>
}

#include "scriptcontrolqueue.h"
#include "qvaluelist.h"
#include "qdatetime.h"

class LuaInterface {
	public:
		LuaInterface(ScriptControlQueue* q);
		~LuaInterface();
		
		void stop(int channel);
		void play(int channel);
		void setFader(double fade);
		void test();
		
		void executeScript(const char *script);
		
		void startFadeCrossfader();
		void startFade(const char* group, const char* name);
		void fadePoint(int time, double value);
		void endFade();
	private:
		ScriptControlQueue* m_q;
		lua_State* m_L;
		
		QDateTime m_time;
		QValueList<int>* m_times;
		QValueList<double>* m_values;
		
		const char* m_group;
		const char* m_name;
};

#endif
