#pragma once
//========================================
// Config.h - MuEMU Reworked Graphics System
// Configuración central del sistema
//========================================

// ============ TIPOS DE ELEMENTOS UI ============
enum UIElementType {
    UI_NONE = 0,
    UI_WINDOW,
    UI_BUTTON,
    UI_LABEL,
    UI_TEXTBOX,
    UI_CHECKBOX,
    UI_SLIDER,
    UI_IMAGE,
    UI_PROGRESSBAR,
    UI_COMBOBOX,
    UI_LISTBOX,
    UI_PANEL,
    UI_TOOLTIP
};

// ============ TIPOS DE EFECTOS ============
enum EffectType {
    EFFECT_NONE = 0,
    EFFECT_GLOW,
    EFFECT_SHADOW,
    EFFECT_BLUR,
    EFFECT_BLOOM,
    EFFECT_OUTLINE,
    EFFECT_GRADIENT
};

// ============ MODOS DE MEZCLA ============
enum BlendMode {
    BLEND_NONE = 0,
    BLEND_NORMAL,
    BLEND_ADDITIVE,
    BLEND_MULTIPLY,
    BLEND_SCREEN,
    BLEND_OVERLAY
};

// ============ COLORES ADICIONALES ============
#define eCyan Color4f(0, 255, 255, 255)

namespace Config {
    // ============ DEBUG ============
    constexpr bool ENABLE_DEBUG_LOG = true;        // Habilitar consola de debug
    constexpr bool SHOW_FPS_COUNTER = true;        // Mostrar contador de FPS
    constexpr bool SHOW_DEBUG_INFO = false;        // Mostrar información adicional de debug

    // ============ GRAPHICS ============
    constexpr bool ENABLE_ANTIALIASING = true;     // Habilitar antialiasing
    constexpr bool ENABLE_VSYNC = true;            // Habilitar sincronización vertical
    constexpr int MAX_FPS = 60;                    // FPS máximo

    // ============ FOG SYSTEM ============
    constexpr int MAX_FOG_CONFIGS = 200;           // Máximo de configuraciones de niebla
    constexpr float DEFAULT_FOG_DENSITY = 0.25f;   // Densidad por defecto
    constexpr float DEFAULT_FOG_START = 1650.0f;   // Distancia inicial por defecto
    constexpr float DEFAULT_FOG_END = 2100.0f;     // Distancia final por defecto

    // ============ INTERFACE ============
    constexpr int MAX_UI_ELEMENTS = 500;           // Máximo de elementos UI
    constexpr float UI_ANIMATION_SPEED = 0.3f;     // Velocidad de animaciones
    constexpr bool ENABLE_UI_ANIMATIONS = true;    // Habilitar animaciones UI

    // ============ MEMORY ============
    constexpr bool SAFE_MODE = true;               // Modo seguro con validaciones extra
    constexpr bool CHECK_POINTERS = true;          // Verificar punteros antes de usar

    // ============ FEATURES ============
    constexpr bool ENABLE_CUSTOM_FOG = true;       // Habilitar sistema de niebla personalizado
    constexpr bool ENABLE_CUSTOM_UI = true;        // Habilitar UI personalizada
    constexpr bool ENABLE_WEATHER = false;         // Sistema de clima (futuro)
    constexpr bool ENABLE_PARTICLES = false;       // Sistema de partículas (futuro)
}

// ============ MACROS DE LOG ============
#define LOG(fmt, ...)
#define LOG_ERROR(fmt, ...)
#define LOG_WARNING(fmt, ...)

// ============ VALIDACIÓN ============
#define VALIDATE_POINTER(p) if(!(p)) { LOG_ERROR("Invalid pointer at %s:%d", __FILE__, __LINE__); return; }
#define VALIDATE_POINTER_RETURN(p, ret) if(!(p)) { LOG_ERROR("Invalid pointer at %s:%d", __FILE__, __LINE__); return ret; }