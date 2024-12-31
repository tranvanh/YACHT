# YACHT

[SDL](https://www.libsdl.org/) based project.
Efforts to strip common technical challenges present in any game development. Providing interfaces for event loop, entity rendering, texture handling etc. 

**Cannot run on MacOS** <br>
MacOs forbids to run event poll on secondary thread. Switching it with rendering, where we would have a render thread and events would be fetched on main thread is currently not possible as it is against SDL framework

## Disclaimer
Project serves as a practice
