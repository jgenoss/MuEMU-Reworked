// MuMaker - Embedded Resources
// Refactored from Class34

using Microsoft.VisualBasic;
using Microsoft.VisualBasic.CompilerServices;
using System.CodeDom.Compiler;
using System.Diagnostics;
using System.Drawing;
using System.Globalization;
using System.Resources;
using System.Runtime.CompilerServices;

namespace MuMaker.Core
{
    /// <summary>
    /// Provides access to embedded bitmap resources
    /// </summary>
    [DebuggerNonUserCode]
    [StandardModule]
    [HideModuleName]
    [GeneratedCode("System.Resources.Tools.StronglyTypedResourceBuilder", "2.0.0.0")]
    [CompilerGenerated]
    internal sealed class EmbeddedResources
    {
        private static ResourceManager _resourceManager;
        private static CultureInfo _culture;

        /// <summary>
        /// Gets the ResourceManager instance for MuMaker resources
        /// </summary>
        [SpecialName]
        internal static ResourceManager GetResourceManager()
        {
            if (object.ReferenceEquals((object)_resourceManager, (object)null))
            {
                _resourceManager = new ResourceManager("MuMaker.Resources", typeof(EmbeddedResources).Assembly);
            }
            return _resourceManager;
        }

        /// <summary>
        /// Gets the current culture for resource loading
        /// </summary>
        [SpecialName]
        internal static CultureInfo GetCulture()
        {
            return _culture;
        }

        /// <summary>
        /// Sets the culture for resource loading
        /// </summary>
        [SpecialName]
        internal static void SetCulture(CultureInfo culture)
        {
            _culture = culture;
        }

        // Main form backgrounds
        [SpecialName]
        internal static Bitmap GetAccountMakerMain() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("AccountMakerMain", _culture));

        [SpecialName]
        internal static Bitmap GetFindeMakerMain() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("FinderMakerMain", _culture));

        [SpecialName]
        internal static Bitmap GetGuildMakerMain() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("GuildMakerMain", _culture));

        [SpecialName]
        internal static Bitmap GetItemMakerMain() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("ItemMakerMain", _culture));

        [SpecialName]
        internal static Bitmap GetSkillMakerMain() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("SkillMakerMain", _culture));

        [SpecialName]
        internal static Bitmap GetMoveMakerMain() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("MoveMakerMain", _culture));

        [SpecialName]
        internal static Bitmap GetStatsMakerMain() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("StatsMakerMain", _culture));

        [SpecialName]
        internal static Bitmap GetPJMakerMain() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("PJMakerMain", _culture));

        [SpecialName]
        internal static Bitmap GetSearchMakerMain() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("SearchMakerMain", _culture));

        [SpecialName]
        internal static Bitmap GetHelpMakerMain() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("HelpMakerMain", _culture));

        [SpecialName]
        internal static Bitmap GetMainNew() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("MainNew", _culture));

        [SpecialName]
        internal static Bitmap GetConfig() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("Config", _culture));

        [SpecialName]
        internal static Bitmap GetFondo() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("Fondo", _culture));

        [SpecialName]
        internal static Bitmap GetLoging() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("Loging", _culture));

        [SpecialName]
        internal static Bitmap GetCreditos() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("Creditos", _culture));

        // Buttons - Accept/OK
        [SpecialName]
        internal static Bitmap GetAceptar() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("Aceptar", _culture));

        [SpecialName]
        internal static Bitmap GetAceptarDown() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("AceptarDOWN", _culture));

        [SpecialName]
        internal static Bitmap GetOK() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("OK", _culture));

        [SpecialName]
        internal static Bitmap GetOKDown() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("OKDOWN", _culture));

        // Buttons - Cancel/Close
        [SpecialName]
        internal static Bitmap GetCancel() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("Cancel", _culture));

        [SpecialName]
        internal static Bitmap GetCancelDown() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("CancelDOWN", _culture));

        [SpecialName]
        internal static Bitmap GetCerrar() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("Cerrar", _culture));

        [SpecialName]
        internal static Bitmap GetCerrarDown() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("CerrarDOWN", _culture));

        [SpecialName]
        internal static Bitmap GetClose() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("Close", _culture));

        [SpecialName]
        internal static Bitmap GetCloseDown() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("CloseDOWN", _culture));

        [SpecialName]
        internal static Bitmap GetClosed() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("Closed", _culture));

        [SpecialName]
        internal static Bitmap GetClosedDown() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("ClosedDOWN", _culture));

        // Buttons - Main menu
        [SpecialName]
        internal static Bitmap GetBotonAccountMaker() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("BotonAccountMaker", _culture));

        [SpecialName]
        internal static Bitmap GetBotonAccountMakerDown() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("BotonAccountMakerDOWN", _culture));

        [SpecialName]
        internal static Bitmap GetBotonItemMaker() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("BotonItemMaker", _culture));

        [SpecialName]
        internal static Bitmap GetBotonItemMakerDown() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("BotonItemMakerDOWN", _culture));

        [SpecialName]
        internal static Bitmap GetBotonGuildMaker() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("BotonGuildMaker", _culture));

        [SpecialName]
        internal static Bitmap GetBotonGuildMakerDown() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("BotonGuildMakerDOWN", _culture));

        [SpecialName]
        internal static Bitmap GetBotonFinderMaker() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("BotonFinderMaker", _culture));

        [SpecialName]
        internal static Bitmap GetBotonFinderMakerDown() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("BotonFinderMakerDOWN", _culture));

        [SpecialName]
        internal static Bitmap GetBotonSkillMaker() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("BotonSkillMaker", _culture));

        [SpecialName]
        internal static Bitmap GetBotonSkillMakerDown() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("BotonSkillMakerDOWN", _culture));

        [SpecialName]
        internal static Bitmap GetBotonMoveMaker() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("BotonMoveMaker", _culture));

        [SpecialName]
        internal static Bitmap GetBotonMoveMakerDown() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("BotonMoveMakerDOWN", _culture));

        [SpecialName]
        internal static Bitmap GetBotonConfigMaker() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("BotonConfigMaker", _culture));

        [SpecialName]
        internal static Bitmap GetBotonConfigMakerDown() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("BotonConfigMakerDOWN", _culture));

        [SpecialName]
        internal static Bitmap GetBotonSQLMaker() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("BotonSQLMaker", _culture));

        [SpecialName]
        internal static Bitmap GetBotonSQLMakerDown() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("BotonSQLMakerDOWN", _culture));

        [SpecialName]
        internal static Bitmap GetBotonMonsterMaker() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("BotonMonsterMaker", _culture));

        [SpecialName]
        internal static Bitmap GetBotonMonsterMakerDown() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("BotonMonsterMakerDOWN", _culture));

        [SpecialName]
        internal static Bitmap GetBotonShopMaker() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("BotonShopMaker", _culture));

        [SpecialName]
        internal static Bitmap GetBotonShopMakerDown() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("BotonShopMakerDOWN", _culture));

        [SpecialName]
        internal static Bitmap GetBotonReserved() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("BotonReserverd", _culture));

        // Buttons - Common actions
        [SpecialName]
        internal static Bitmap GetBotonBuscar() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("BotonBuscar", _culture));

        [SpecialName]
        internal static Bitmap GetBotonBuscarDown() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("BotonBuscarDOWN", _culture));

        [SpecialName]
        internal static Bitmap GetBotonZen() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("BotonZen", _culture));

        [SpecialName]
        internal static Bitmap GetBotonZenDown() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("BotonZenDOWN", _culture));

        [SpecialName]
        internal static Bitmap GetConnect() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("Connect", _culture));

        [SpecialName]
        internal static Bitmap GetConnectDown() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("ConnectDOWN", _culture));

        [SpecialName]
        internal static Bitmap GetCreate() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("Create", _culture));

        [SpecialName]
        internal static Bitmap GetCreateDown() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("CreateDOWN", _culture));

        [SpecialName]
        internal static Bitmap GetDelete() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("Delete", _culture));

        [SpecialName]
        internal static Bitmap GetDeleteDown() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("DeleteDOWN", _culture));

        [SpecialName]
        internal static Bitmap GetReload() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("Reload", _culture));

        [SpecialName]
        internal static Bitmap GetReloadDown() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("ReloadDOWN", _culture));

        [SpecialName]
        internal static Bitmap GetManual() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("Manual", _culture));

        [SpecialName]
        internal static Bitmap GetManualDown() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("ManualDOWN", _culture));

        [SpecialName]
        internal static Bitmap GetMinimizar() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("Minimizar", _culture));

        [SpecialName]
        internal static Bitmap GetMinimizarDown() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("MinimizarDOWN", _culture));

        [SpecialName]
        internal static Bitmap GetVault() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("Vault", _culture));

        [SpecialName]
        internal static Bitmap GetVaultDown() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("VaultDOWN", _culture));

        // Inventory buttons
        [SpecialName]
        internal static Bitmap GetInvent01() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("Invent01", _culture));

        [SpecialName]
        internal static Bitmap GetInvent01Down() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("Invent01DOWN", _culture));

        [SpecialName]
        internal static Bitmap GetInvent02() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("Invent02", _culture));

        [SpecialName]
        internal static Bitmap GetInvent02Down() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("Invent02DOWN", _culture));

        // Item category icons
        [SpecialName]
        internal static Bitmap GetWeapons() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("Weapons", _culture));

        [SpecialName]
        internal static Bitmap GetArmors() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("Armors", _culture));

        [SpecialName]
        internal static Bitmap GetHelms() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("Helms", _culture));

        [SpecialName]
        internal static Bitmap GetGloves() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("Gloves", _culture));

        [SpecialName]
        internal static Bitmap GetPants() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("Pants", _culture));

        [SpecialName]
        internal static Bitmap GetBoots() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("Boots", _culture));

        [SpecialName]
        internal static Bitmap GetShields() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("Shields", _culture));

        [SpecialName]
        internal static Bitmap GetWings() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("Wings", _culture));

        [SpecialName]
        internal static Bitmap GetRings() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("Rings", _culture));

        [SpecialName]
        internal static Bitmap GetPendants() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("Pendants", _culture));

        [SpecialName]
        internal static Bitmap GetGuardians() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("Guardians", _culture));

        // Language flags
        [SpecialName]
        internal static Bitmap GetArabe() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("Arabe", _culture));

        [SpecialName]
        internal static Bitmap GetChino() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("Chino", _culture));

        [SpecialName]
        internal static Bitmap GetDeutsch() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("Deutsch", _culture));

        [SpecialName]
        internal static Bitmap GetEnglish() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("English", _culture));

        [SpecialName]
        internal static Bitmap GetEspanol() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("Espanol", _culture));

        [SpecialName]
        internal static Bitmap GetFrench() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("French", _culture));

        [SpecialName]
        internal static Bitmap GetItaliano() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("Italiano", _culture));

        [SpecialName]
        internal static Bitmap GetKorean() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("Korean", _culture));

        [SpecialName]
        internal static Bitmap GetLatviski() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("Latviski", _culture));

        [SpecialName]
        internal static Bitmap GetPolish() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("Polish", _culture));

        [SpecialName]
        internal static Bitmap GetPortBra() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("PortBra", _culture));

        [SpecialName]
        internal static Bitmap GetRuso() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("Ruso", _culture));

        // UI elements
        [SpecialName]
        internal static Bitmap GetBarraLoad() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("BarraLoad", _culture));

        [SpecialName]
        internal static Bitmap GetBoxZEN() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("BoxZEN", _culture));

        [SpecialName]
        internal static Bitmap GetCasilla() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("Casilla", _culture));

        [SpecialName]
        internal static Bitmap GetCharacterEX() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("CharacterEX", _culture));

        [SpecialName]
        internal static Bitmap GetEditDefaults() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("EditDefaults", _culture));

        [SpecialName]
        internal static Bitmap GetElfo() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("Elfo", _culture));

        [SpecialName]
        internal static Bitmap GetFuego() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("Fuego", _culture));

        [SpecialName]
        internal static Bitmap GetInf() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("Inf", _culture));

        [SpecialName]
        internal static Bitmap GetInventario() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("Inventario", _culture));

        [SpecialName]
        internal static Bitmap GetLinckRed() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("LinckRed", _culture));

        [SpecialName]
        internal static Bitmap GetMark() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("Mark", _culture));

        [SpecialName]
        internal static Bitmap GetOFF() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("OFF", _culture));

        [SpecialName]
        internal static Bitmap GetONN() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("ONN", _culture));

        [SpecialName]
        internal static Bitmap GetPJ() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("PJ", _culture));

        [SpecialName]
        internal static Bitmap GetTablaItems() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("TablaItems", _culture));

        // Branding
        [SpecialName]
        internal static Bitmap GetDownloadMMK() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("DownloadMMK", _culture));

        [SpecialName]
        internal static Bitmap GetPaypal() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("paypal", _culture));

        [SpecialName]
        internal static Bitmap GetTMTBOX() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("TMTBOX", _culture));

        [SpecialName]
        internal static Bitmap GetTMTLOGO() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("TMTLOGO", _culture));

        [SpecialName]
        internal static Bitmap GetUpDater() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("UpDater", _culture));

        [SpecialName]
        internal static Bitmap GetVersion() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("Version", _culture));

        [SpecialName]
        internal static Bitmap GetX() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("X", _culture));

        [SpecialName]
        internal static Bitmap GetXDown() => (Bitmap)RuntimeHelpers.GetObjectValue(GetResourceManager().GetObject("XDOWN", _culture));
    }
}
