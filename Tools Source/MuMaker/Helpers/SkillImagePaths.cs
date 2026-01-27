// MuMaker - Skill Image Paths
// Refactored from Class33

using Microsoft.VisualBasic.CompilerServices;

namespace MuMaker.Helpers
{
    /// <summary>
    /// Image paths for skills
    /// </summary>
    [StandardModule]
    internal sealed class SkillImagePaths
    {
        /// <summary>Default/unknown skill image</summary>
        public static string DefaultSkillImage = "Img\\Skills\\999999.mmk";

        /// <summary>Current skill image path (dynamic)</summary>
        public static string CurrentSkillImagePath;
    }
}
