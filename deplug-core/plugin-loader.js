import ComponentFactory from './components/factory'
import Plugin from './plugin'
import Profile from './profile'

let plugins = null
export default class PluginLoader {
  static async loadComponents (type) {
    if (plugins === null) {
      plugins = await Plugin.listPlugins()
    }
    const tasks = []
    for (const plugin of plugins) {
      Profile.setPluginDefault(plugin.pkg.name, 'enabled', true)
      const { enabled } = Profile.current[`$${plugin.pkg.name}`]
      if (enabled) {
        for (const opt of plugin.options) {
          if ('default' in opt) {
            Profile.setPluginDefault(plugin.pkg.name, opt.id, opt.default)
          }
        }

        for (const comp of plugin.compList) {
          if (comp.type === type) {
            const builtComponent =
              ComponentFactory.create(plugin.rootDir, plugin.pkg, comp)
            tasks.push(builtComponent.load())
          }
        }
      }
    }
    return Promise.all(tasks)
  }
}
