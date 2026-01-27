// MuMaker - Skill Image Paths
// Refactored from Class33

using Microsoft.VisualBasic.CompilerServices;

namespace MuMaker.Helpers
{
    /// <summary>
    /// Image paths for skills
    /// Maintains backward compatibility with original field names
    /// </summary>
    [StandardModule]
    internal sealed class SkillImagePaths
    {
        // Original field names for backward compatibility
        public static string string_1 = "Img\\Skills\\999999.mmk";  // Default/unknown skill
        public static string string_0;  // Current skill image path
    }
}
