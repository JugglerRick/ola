/*
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Library General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 *
 * pluginloader.h
 * Interface for the pluginloader class
 * Copyright (C) 2005  Simon Newton
 */

#ifndef PLUGINLOADER_H
#define PLUGINLOADER_H

#include <map>
#include <vector>

#include <lla/plugin.h>

using namespace std;

class PluginLoader {

	public:
		PluginLoader(class PluginAdaptor *pa) ;
		~PluginLoader() ;

		int load_plugins(const string &dirname) ;
		int unload_plugins() ;
		int plugin_count() ;
		Plugin *get_plugin(int id) ;
	protected:
		
	private:
		PluginLoader(const PluginLoader&);
		PluginLoader operator=(const PluginLoader&);

		Plugin *load_plugin(const string &path) ;
		int unload_plugin(void *handle) ;
		
		vector<Plugin*>	 m_plugin_vect ;
		class PluginAdaptor *pa ;
		map<void*, Plugin*> m_plugin_map ;

};

#endif
