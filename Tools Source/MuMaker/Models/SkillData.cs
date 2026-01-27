// MuMaker - Skill Data Models
// Refactored from Class25

using Microsoft.VisualBasic.CompilerServices;

namespace MuMaker.Models
{
    /// <summary>
    /// Skill data structure containing skill properties
    /// </summary>
    [StandardModule]
    internal sealed class SkillData
    {
        /// <summary>Current skill being viewed/edited</summary>
        public static SkillInfo CurrentSkill;

        /// <summary>Temporary skill data</summary>
        public static SkillInfo TempSkill;

        /// <summary>Selected skill from database</summary>
        public static SkillInfo SelectedSkill;

        /// <summary>
        /// Structure containing skill information
        /// </summary>
        public struct SkillInfo
        {
            /// <summary>Skill number (Nº field)</summary>
            public string SkillNumber;

            /// <summary>Skill ID</summary>
            public string SkillId;

            /// <summary>Skill type indicator (68 = Pet/Item)</summary>
            public string SkillTypeCode;

            /// <summary>Skill name</summary>
            public string Name;

            /// <summary>Skill type description</summary>
            public string Type;

            /// <summary>Skill range</summary>
            public string Range;

            /// <summary>Mana cost</summary>
            public string ManaCost;

            /// <summary>Stamina cost</summary>
            public string StaminaCost;

            /// <summary>Formatted skill tooltip text</summary>
            public string TooltipText;
        }
    }
}
