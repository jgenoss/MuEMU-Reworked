// MuMaker - Skill Data Models
// Refactored from Class25
// Maintains backward compatibility with original field names

using Microsoft.VisualBasic.CompilerServices;

namespace MuMaker.Models
{
    /// <summary>
    /// Skill information structure (Struct5)
    /// </summary>
    public struct Struct5
    {
        public string string_0;  // Skill number (Nº)
        public string string_1;  // Skill ID
        public string string_2;  // Skill type code (68 = Pet/Item)
        public string string_3;  // Skill name
        public string string_4;  // Skill type description
        public string string_5;  // Skill range
        public string string_6;  // Mana cost
        public string string_7;  // Stamina cost
        public string string_8;  // Formatted tooltip text
    }

    /// <summary>
    /// Skill data manager - replaces Class25
    /// </summary>
    [StandardModule]
    internal sealed class SkillData
    {
        public static Struct5 struct5_0;  // Current skill being viewed/edited
        public static Struct5 struct5_1;  // Temporary skill data
        public static Struct5 struct5_2;  // Selected skill from database

        // Descriptive aliases
        public static Struct5 CurrentSkill { get => struct5_0; set => struct5_0 = value; }
        public static Struct5 TempSkill { get => struct5_1; set => struct5_1 = value; }
        public static Struct5 SelectedSkill { get => struct5_2; set => struct5_2 = value; }
    }
}
