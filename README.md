# MuEMU-Reworked 🎮

[![License](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)
[![Platform](https://img.shields.io/badge/platform-Windows-lightgrey.svg)]()
[![Status](https://img.shields.io/badge/status-Active-green.svg)]()

## 📋 Descripción

**MuEMU-Reworked** es un emulador de servidor mejorado y reescrito para el popular MMORPG **MU Online**, específicamente diseñado para las temporadas **Season 4, Season 6 y Season 8**. Este proyecto representa una versión refinada y optimizada del emulador MuEMU original, desarrollado por JGenoss con el objetivo de proporcionar una experiencia de servidor más estable, eficiente y rica en características para estas temporadas clásicas.

### ¿Qué es MU Online?

MU Online es un MMORPG (Massively Multiplayer Online Role-Playing Game) de fantasía medieval desarrollado originalmente por Webzen en 2001. El juego se caracteriza por su sistema de clases diverso, PvP intenso, sistema de gremios y eventos especiales. A lo largo de los años, ha evolucionado a través de múltiples temporadas (seasons) que han añadido nuevas características, mapas, items y mecánicas de juego.

### ¿Qué es un Emulador de Servidor?

Un emulador de servidor es un software que replica la funcionalidad del servidor oficial del juego, permitiendo a los administradores crear sus propios servidores privados con reglas personalizadas, rates modificados y características únicas.

## ✨ Características Principales

### 🔧 Mejoras del Sistema
- **Arquitectura Optimizada**: Código reescrito para mejor rendimiento y estabilidad
- **Gestión Avanzada de Memoria**: Optimización en el uso de recursos del sistema
- **Sistema de Logs Mejorado**: Registro detallado de eventos para debugging
- **Configuración Flexible**: Archivos de configuración XML/INI fáciles de modificar
- **Desbloqueo de FPS**: Eliminación del límite de 30 FPS para mejor fluidez
- **Correcciones de Código**: Múltiples fixes y optimizaciones del código original

### 🎯 Características del Juego
- **Soporte Multi-Season**: Compatible con Season 4, 6 y 8 del cliente
- **Sistema de Clases Season 4-8**: Dark Knight, Dark Wizard, Elf (Season 4-6), Magic Gladiator (Season 6+), Dark Lord (Season 8+)
- **Sistema PvP Avanzado**: Batallas jugador vs jugador con ranking
- **Eventos Clásicos**: Blood Castle, Devil Square, Chaos Castle (Season 6+), Golden Invasion
- **Sistema de Gremios**: Creación y gestión de guilds con guerra de gremios
- **Sistema de Comercio**: Trade entre jugadores y personal shop
- **Sistema de Crafting**: Creación y mejora de items

### 🆕 Características Custom Exclusivas
- **Sistema CustomPing**: Visualización en tiempo real del ping y FPS del jugador
- **Flying Dragon Effect**: Efecto visual personalizado de invasión (no incluido en código base)
- **Optimizaciones de Rendimiento**: Mejoras específicas en el motor gráfico
- **Interface Mejorada**: HUD personalizado con información adicional

### 🛠 Herramientas Administrativas
- **Panel de Administración Web**: Interfaz web para gestión del servidor
- **Comandos GM**: Sistema completo de comandos para administradores
- **Sistema Anti-Hack**: Protecciones contra cheats y exploits
- **Base de Datos Optimizada**: Soporte para SQL Server/MySQL
- **Sistema de Backup**: Respaldo automático de datos críticos

## 🚀 Instalación

### Requisitos del Sistema

#### Mínimos
- **SO**: Windows 10/11 (64-bit)
- **RAM**: 4 GB
- **Almacenamiento**: 10 GB de espacio libre
- **Red**: Conexión a Internet estable
- **.NET Framework**: 4.7.2 o superior

#### Recomendados para Season 4-8
- **SO**: Windows Server 2019/2022
- **RAM**: 8 GB o más (4 GB mínimo para Season 4)
- **Almacenamiento**: SSD con 15 GB+ de espacio libre
- **CPU**: Procesador multi-core de 2.5 GHz+
- **Base de Datos**: SQL Server 2016+ o MySQL 5.7+

### Pasos de Instalación

1. **Clonar el Repositorio**
   ```bash
   git clone https://github.com/jgenoss/MuEMU-Reworked.git
   cd MuEMU-Reworked
   ```

2. **Configurar Base de Datos**
   - Crear una base de datos nueva en SQL Server/MySQL
   - Ejecutar los scripts SQL incluidos en `/Database/Scripts/`
   - Configurar la conexión en `DataServer.ini`

3. **Configurar Archivos**
   - Editar `ConnectServer.ini` con la IP y puertos del servidor
   - Configurar `GameServer.ini` según las preferencias
   - Ajustar `DataServer.ini` con los datos de conexión de BD

4. **Compilar el Proyecto**
   - Abrir la solución en Visual Studio 2019/2022
   - Restaurar paquetes NuGet si es necesario
   - Compilar en modo Release

5. **Ejecutar Servidores**
   ```
   1. DataServer.exe
   2. ConnectServer.exe
   3. GameServer.exe
   ```

## 🎨 Características Custom Detalladas

### Sistema CustomPing
El sistema CustomPing proporciona información en tiempo real sobre el rendimiento de la conexión:

**Características:**
- Visualización del ping en milisegundos
- Monitor de FPS en tiempo real
- Indicador visual de calidad de conexión
- Configuración personalizable de posición en pantalla

**Configuración:**
```ini
[CUSTOM_PING]
Enable = 1
ShowFPS = 1
ShowPing = 1
Position_X = 10
Position_Y = 10
UpdateInterval = 1000
```

### Flying Dragon Effect
Efecto visual especial para eventos de invasión que añade dramatismo y espectacularidad:

**Características:**
- Animación de dragón volador durante invasiones
- Efectos de partículas mejorados
- Sonidos ambientales personalizados
- Compatible con todos los mapas

**Nota:** Este efecto es una adición custom y no está incluido en el código base original.

### Desbloqueo de FPS
Eliminación de la limitación de 30 FPS del cliente original:

**Beneficios:**
- Experiencia de juego más fluida
- Mejor respuesta en combate PvP
- Animaciones más suaves
- Compatibilidad con monitores de alta frecuencia

**Configuración:**
```ini
[FPS_SETTINGS]
UnlockFPS = 1
MaxFPS = 120
VSync = 0
```

### Correcciones de Código
Múltiples optimizaciones y fixes implementados:

- **Memory Leaks**: Corrección de fugas de memoria
- **Crash Fixes**: Solución de crashes conocidos
- **Performance**: Optimizaciones de rendimiento
- **Stability**: Mejoras en estabilidad del servidor
- **Security**: Parches de seguridad adicionales

## ⚙️ Configuración

### Archivos de Configuración Principales

#### `GameServer.ini`
```ini
[SERVER_INFO]
ServerName = MuEMU Reworked
ServerPort = 55901
MaxUsers = 1000
ExperienceRate = 100
DropRate = 50
```

#### `ConnectServer.ini`
```ini
[CONNECTION]
ServerIP = 192.168.1.100
Port = 44405
MaxConnections = 1000
```

### Configuraciones Recomendadas para Principiantes
- **Experience Rate**: 50-100x (equilibrio entre progresión y diversión)
- **Drop Rate**: 30-50% (suficiente para obtener items sin ser excesivo)
- **Max Level**: 400 (permite progresión completa)
- **PK Clear**: Habilitado (reduce griefing)
- **CustomPing**: Activado para monitoreo de rendimiento
- **FPS Unlock**: Habilitado para mejor experiencia visual

### Eventos Automáticos (Season 4-8)

#### Season 4-6
- **Blood Castle**: Cada 3 horas
- **Devil Square**: Cada 2 horas  
- **Golden Invasion**: Cada 4 horas

#### Season 6+
- **Chaos Castle**: Cada 6 horas
- **Illusion Temple**: Semanal

#### Season 8+
- **Kanturu Event**: Cada 12 horas
- **Crywolf**: Semanal

### Sistema de Reset (Season 6-8)
- **Reset Level**: 400 (Season 6+)
- **Grand Reset**: Solo disponible en Season 8
- **Bonus por Reset**: +5 puntos de stat por reset (Season 6+)
- **Reset Stats**: Disponible desde Season 6

*Nota: Season 4 no incluye sistema de reset oficial*

## 🏗 Arquitectura del Proyecto

```
MuEMU-Reworked/
├── Source/
│   ├── ConnectServer/     # Servidor de conexiones
│   ├── DataServer/        # Servidor de base de datos
│   ├── GameServer/        # Servidor principal del juego
│   ├── Common/           # Librerías compartidas
│   └── CustomSystems/    # Sistemas personalizados (CustomPing, FPS, etc.)
├── Database/
│   ├── Scripts/          # Scripts SQL
│   └── Procedures/       # Procedimientos almacenados
├── Config/               # Archivos de configuración
├── Client/              # Archivos del cliente
├── Effects/             # Efectos visuales custom (Flying Dragon, etc.)
└── Tools/               # Herramientas auxiliares
```

## 🤝 Contribución

Las contribuciones son bienvenidas. Para contribuir:

1. Fork el proyecto
2. Crea una rama para tu feature (`git checkout -b feature/AmazingFeature`)
3. Commit tus cambios (`git commit -m 'Add some AmazingFeature'`)
4. Push a la rama (`git push origin feature/AmazingFeature`)
5. Abre un Pull Request

### Estándares de Código
- Usar nomenclatura clara y descriptiva
- Comentar código complejo
- Seguir las convenciones de C#
- Incluir pruebas para nuevas funcionalidades

## 🐛 Reporte de Bugs

Si encuentras un bug, por favor:

1. Verifica que no haya sido reportado anteriormente
2. Crea un issue detallado con:
   - Descripción del problema
   - Pasos para reproducir
   - Comportamiento esperado vs actual
   - Screenshots si es relevante
   - Información del sistema

## 📚 Recursos Adicionales

### Documentación
- [Guía de Configuración Avanzada](docs/advanced-config.md)
- [API de Scripts](docs/scripting-api.md)
- [Troubleshooting](docs/troubleshooting.md)

### Comunidad
- [Discord Server](https://discord.gg/muemu)
- [Foro de Soporte](https://forum.muemu-reworked.com)
- [Wiki del Proyecto](https://wiki.muemu-reworked.com)

### Tools Útiles
- [MU Editor](https://github.com/user/mu-editor) - Editor de items y mapas
- [Client Patcher](https://github.com/user/mu-patcher) - Parchador de cliente
- [Stats Calculator](https://github.com/user/mu-calculator) - Calculadora de stats

## 📊 Estado del Proyecto

### Temporadas Soportadas
- ✅ **Season 4** (Completo) - Temporada clásica con 3 clases básicas
- ✅ **Season 6** (Completo) - Incluye Magic Gladiator, Chaos Castle, Sistema de Reset
- ✅ **Season 8** (Completo) - Añade Dark Lord, Kanturu, Crywolf, Grand Reset

### Características por Temporada

#### Season 4
- ✅ 3 Clases básicas (DK, DW, Elf) (100%)
- ✅ Sistema PvP clásico (100%)
- ✅ Blood Castle y Devil Square (100%)
- ✅ Sistema de Gremios básico (100%)
- ✅ CustomPing System (100%)
- ✅ FPS Unlock (100%)

#### Season 6  
- ✅ Magic Gladiator (100%)
- ✅ Chaos Castle (100%)
- ✅ Sistema de Reset (100%)
- ✅ Jewels mejoradas (100%)
- ✅ Flying Dragon Effect (100%)
- ✅ Optimizaciones de código (100%)

#### Season 8
- ✅ Dark Lord (100%)
- ✅ Kanturu Event (100%) 
- ✅ Crywolf (95%)
- 🔄 Sistema de Mascotas (85%)
- ✅ Todas las mejoras custom (100%)

## ⚖️ Licencia

Este proyecto está licenciado bajo la Licencia MIT. Ver [LICENSE](LICENSE) para más detalles.

## 👨‍💻 Autor

**JGenoss** - [GitHub Profile](https://github.com/jgenoss)

## 🙏 Agradecimientos

- Al equipo original de Webzen por crear MU Online
- A la comunidad de desarrolladores de emuladores de MU
- A todos los contribuidores que han mejorado este proyecto
- A los administradores de servidores que prueban y reportan bugs

## 📞 Soporte

Para soporte técnico:
- **Email**: granadillo33@gmail.com
- **Discord**: jgenoss
- **Issues**: Use la sección de Issues de GitHub

---

**¿Te gusta el proyecto?** ⭐ ¡Dale una estrella en GitHub!

**¿Necesitas ayuda?** 💬 Únete a nuestra comunidad en Discord

**¿Quieres contribuir?** 🔧 Revisa nuestros issues abiertos
