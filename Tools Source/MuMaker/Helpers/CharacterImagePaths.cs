// MuMaker - Character Image Paths
// Refactored from Class27

using Microsoft.VisualBasic.CompilerServices;

namespace MuMaker.Helpers
{
    /// <summary>
    /// Image paths for different character classes and their evolutions
    /// </summary>
    [StandardModule]
    internal sealed class CharacterImagePaths
    {
        // Unknown/Default character image
        public static string UnknownCharacter = "Img\\Pj\\999999.mmk";

        // Dark Knight (Class 0) - Base, Blade Knight, Blade Master
        public static string DarkKnightBase = "Img\\Pj\\000.mmk";
        public static string DarkKnight = "Img\\Pj\\000000.mmk";
        public static string BladeKnight = "Img\\Pj\\000001.mmk";
        public static string BladeMaster = "Img\\Pj\\000002.mmk";
        public static string BladeMaster2 = "Img\\Pj\\000002.mmk";

        // Dark Wizard (Class 16) - Base, Soul Master, Grand Master
        public static string DarkWizardBase = "Img\\Pj\\016.mmk";
        public static string DarkWizard = "Img\\Pj\\016016.mmk";
        public static string SoulMaster = "Img\\Pj\\016017.mmk";
        public static string GrandMaster = "Img\\Pj\\016018.mmk";
        public static string GrandMaster2 = "Img\\Pj\\016018.mmk";

        // Fairy Elf (Class 32) - Base, Muse Elf, High Elf
        public static string FairyElfBase = "Img\\Pj\\032.mmk";
        public static string FairyElf = "Img\\Pj\\032032.mmk";
        public static string MuseElf = "Img\\Pj\\032033.mmk";
        public static string HighElf = "Img\\Pj\\032034.mmk";
        public static string HighElf2 = "Img\\Pj\\032034.mmk";

        // Magic Gladiator (Class 48) - Base, Duel Master
        public static string MagicGladiatorBase = "Img\\Pj\\048.mmk";
        public static string MagicGladiator = "Img\\Pj\\048048.mmk";
        public static string DuelMaster = "Img\\Pj\\048049.mmk";
        public static string DuelMaster2 = "Img\\Pj\\048050.mmk";

        // Dark Lord (Class 64) - Base, Lord Emperor
        public static string DarkLordBase = "Img\\Pj\\064.mmk";
        public static string DarkLord = "Img\\Pj\\064064.mmk";
        public static string LordEmperor = "Img\\Pj\\064065.mmk";
        public static string LordEmperor2 = "Img\\Pj\\064066.mmk";

        // Summoner (Class 80) - Base, Bloody Summoner, Dimension Master
        public static string SummonerBase = "Img\\Pj\\080.mmk";
        public static string Summoner = "Img\\Pj\\080080.mmk";
        public static string BloodySummoner = "Img\\Pj\\080081.mmk";
        public static string DimensionMaster = "Img\\Pj\\080082.mmk";
        public static string DimensionMaster2 = "Img\\Pj\\080082.mmk";

        // Rage Fighter / Monk (Class 96) - NEED NEW IMAGE
        public static string RageFighterBase = "Img\\Pj\\080.mmk"; // Placeholder - needs new image
    }
}
