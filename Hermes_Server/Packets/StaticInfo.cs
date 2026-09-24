// This file contains a bunch of static info. Will probably 
// be used for stuff like .ini config files, or other stuff I 
// don't care about yet. 

using Microsoft.Extensions.Configuration;

public class AppConfig()
{
    public static IConfigurationRoot config;
    public static IConfigurationRoot GetConfig()
    {
        if (config == null)
        {
            config = new ConfigurationBuilder().SetBasePath(AppContext.BaseDirectory)
            .AddJsonFile("appsettings.json", optional: false, reloadOnChange: true)
            .Build();
        }
        return config;
    }
}

// VALID INFO AS OF 1.112.0 (yes I know that a gregor EGO is coming, shut up)
public static class StaticSinnerEGOInfo
{
    // ids are formatted like 2XXYY, where XX = Sinner, YY = EGO uid. 
    // Yi Sang = 1 -> Gregor = 12 
    public static List<int> SinnerEGOCounts = new List<int> {
        9, // Yi Sang
        10, // Faust 
        10, // Don
        9, // R.
        9, // Consider it done, Manager.
        9, // Chinese
        9, // Oi matey
        10, // MY COMPASS IS CURIOSITY!!
        9,  // Nothing special
        9, // Between two worlds
        9, // The Glaze NEVER ends
        9 // Gregreg
    };

    public static List<int> GetAllEGOIds()
    {
        List<int> egoList = new List<int>();
        for (int i = 0; i < SinnerEGOCounts.Count; i++)
        {
            int egoAmt = SinnerEGOCounts[i];
            for (int egoNum = 0; egoNum < egoAmt; egoNum++)
            {
                //          2           XX              YY
                int id = (20000) + ((i + 1) * 100) + (egoNum + 1);
                egoList.Add(id);
            }
        }
        return egoList;
    }

}

public static class StaticSinnerPersonalityInfo
{
    // ids are formatted like 2XXYY, where XX = Sinner, YY = EGO uid. 
    // Yi Sang = 1 -> Gregor = 12 
    public static List<int> SinnerIDCounts = new List<int> {
        16, // Yi Sang
        16, // Faust 
        14, // Don
        15, // R.
        15, // Consider it done, Manager.
        16, // Chinese
        16, // Oi matey
        15, // MY COMPASS IS CURIOSITY!!
        16,  // Nothing special
        15, // Between two worlds
        15, // The Glaze NEVER ends
        16 // Gregreg
    };

    // Index is the sinner (0 = yisang, 11 = greg), list is rarity (2 = 2 star, 3 = 3 star, 1 = 1 star (base id))
    public static List<List<int>> SinnerRarities = new List<List<int>> {
        new List<int>{1,2,3,3,2,3,2,2,3,3,2,3,3,3,3,3}, // Yi Sang
        new List<int>{1,2,2,3,2,3,3,3,2,3,3,3,3,3,3,3}, // Faust
        new List<int>{1,3,2,2,3,3,2,2,3,3,3,3,3,3}, // Don Quixote
        new List<int>{1,2,3,3,3,2,2,3,2,3,3,3,3,3,3}, // Ryoshu
        new List<int>{1,2,3,3,2,3,2,3,2,3,3,3,3,3,3}, // Meursault
        new List<int>{1,2,3,2,3,2,2,3,3,2,3,3,3,3,3,3}, // Hong Lu
        new List<int>{1,2,3,2,3,2,3,3,3,3,3,3,3,3,3,3}, // Heathcliff
        new List<int>{1,3,2,2,2,3,3,3,2,3,3,3,3,3,3}, // Ishmael 
        new List<int>{1,3,2,2,3,2,3,3,2,3,3,3,3,3,3,3}, // Rodion
        new List<int>{1,3,2,2,3,2,2,3,3,2,3,3,3,3,3}, // Sinclair
        new List<int>{1,2,2,3,3,2,3,3,2,3,3,3,3,3,3}, // Outis 
        new List<int>{1,2,3,2,2,3,3,2,3,3,3,3,3,3,3,3} // Gregor
    };
    
    private static List<int> FourStarIDs = new List<int>(); // wow! incredible stuff. 
    private static List<int> ThreeStarIDs = new List<int>();
    private static List<int> TwoStarIDs = new List<int>();
    private static List<int> OneStarIDs = new List<int>();

    public static List<int> Get3StarIDs()
    {
        if (ThreeStarIDs.Count == 0)
        {
            InitIDLists();
        }
        return ThreeStarIDs;
    }

    public static List<int> Get4StarIDs()
    {
        if (FourStarIDs.Count == 0)
        {
            InitIDLists();
        }
        return FourStarIDs;
    }

    public static List<int> Get2StarIDs()
    {
        if (TwoStarIDs.Count == 0)
        {
            InitIDLists();
        }
        return TwoStarIDs;
    }

    public static List<int> Get1StarIDs()
    {
        if (OneStarIDs.Count == 0)
        {
            InitIDLists();
        }
        return OneStarIDs;
    }

    

    private static void InitIDLists()
    {
        for (int sinner = 0; sinner < SinnerRarities.Count; sinner++)
        {
            List<int> SinnerRarityList = SinnerRarities[sinner];
            for (int personality = 0; personality < SinnerRarityList.Count; personality++)
            {
                int rarity = SinnerRarityList[personality];
                int personalityID = (10000) + ((sinner + 1) * 100) + (personality + 1);
                if (rarity == 1)
                {
                    OneStarIDs.Add(personalityID);
                } else if (rarity == 2)
                {
                    TwoStarIDs.Add(personalityID);
                } else if (rarity == 3)
                {
                    ThreeStarIDs.Add(personalityID);
                } else if (rarity == 4)
                {
                    FourStarIDs.Add(personalityID);
                } else
                {
                    
                }
            } 

        }
    }
     
    public static List<int> GetAllPersonalityIDs()
    {
        List<int> egoList = new List<int>();
        for (int i = 0; i < SinnerIDCounts.Count; i++)
        {
            int idAmt = SinnerIDCounts[i];
            for (int num = 0; num < idAmt; num++)
            {
                //          1           XX              YY
                int id = (10000) + ((i + 1) * 100) + (num + 1);
                egoList.Add(id);
            }
        }

        foreach (int id in ModInfo.ModdedSinners)
        {
            egoList.Add(id);
        }
        return egoList;
    }



}
public static class ModInfo
{
    // add any modded sinners to the diddy list. 
    public static List<int> ModdedSinners = new List<int>
    {
        10199, 10299, 10399
    };
}
public static class StaticChapterInfo
{
    // Prologue -> Canto 9 (no intervallos or other content)
    public static List<int> MainChapterNodeCounts = new List<int>
    {
        4, // Prologue
        11, // C1
        19, // C2
        22, // C3
        54, // C4
        39, // C5
        48, // C6
        36, // C7
        33, // C8
        51, // C9
    };

    public static List<int> SideChapterNodeCounts = new List<int>
    {
        0,
        0,
        0, // first 3 don't exist
        10, // 03
        12, // 04
        13, // 05
        3, // 06
        12, // 07
        3, // 08
        15, // 09
        15, // 10
        4, // 11
        13, // 12
        4, // 13
        14, // 14
        12, // 15
        12, // 16
        4, // 17
        15, // 18
        12, // 19
        14, // 20
        14, // 21
        15, // 22
        4, // 23
        14, // 24
        14, // 25
        12, // 26
        12, // 27
    };


}

public class FastWeightedSelector<T>
{
    private readonly T[] _items;
    private readonly double[] _cumulativeWeights;
    private readonly double _totalWeight;
    private readonly Random _random = new Random();

    public FastWeightedSelector(T[] items, double[] weights)
    {
        if (items.Length != weights.Length || items.Length == 0)
            throw new ArgumentException("Arrays must be matching lengths and non-empty.");

        _items = items;
        _cumulativeWeights = new double[weights.Length];

        // Precompute cumulative totals
        double sum = 0;
        for (int i = 0; i < weights.Length; i++)
        {
            sum += weights[i];
            _cumulativeWeights[i] = sum;
        }
        _totalWeight = sum;
    }

    public T SelectRandomItem()
    {
        double target = _random.NextDouble() * _totalWeight;
        
        // BinarySearch finds the target or returns the bitwise complement of the next larger element
        int index = Array.BinarySearch(_cumulativeWeights, target);
        if (index < 0)
        {
            index = ~index; 
        }

        // Clamp to prevent out-of-bounds due to rare floating-point variations
        return _items[Math.Min(index, _items.Length - 1)];
    }
}
