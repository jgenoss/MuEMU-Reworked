// MuMaker - Search State
// Refactored from Class29

using Microsoft.VisualBasic.CompilerServices;

namespace MuMaker.Core
{
    /// <summary>
    /// State variables for search/finder operations
    /// </summary>
    [StandardModule]
    internal sealed class SearchState
    {
        /// <summary>Current account index being processed</summary>
        public static int CurrentAccountIndex = 0;

        /// <summary>Total number of accounts to process</summary>
        public static int TotalAccountCount = 0;

        /// <summary>Current search query or filter</summary>
        public static string SearchQuery = "";

        /// <summary>Current search result or status message</summary>
        public static string SearchResult = "";

        /// <summary>Flag indicating if search is in progress</summary>
        public static bool IsSearching;
    }
}
