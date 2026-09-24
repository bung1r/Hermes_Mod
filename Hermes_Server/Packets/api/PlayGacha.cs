public class reqPlayGacha : reqPacketBase
{
    public int gachaId {get; set;} = -1; // the banner
    public int paymentId {get; set;} = -1; // 0, 1, 2, is paid lunacy, 1 pull free, and 10 pull free
}
public class resPlayGacha : resPacketBase
{
    // public bool rigged = false;
    // public int[] rigList = [10102, 10202, 10302, 10402, 10502, 10602, 10702, 10802, 10902, 11202];
    public List<GachaPull> gachaLogDetails {get; set;} = new List<GachaPull>();
    public resPlayGacha(RequestPacket req)
    {
        reqPlayGacha reqPlayGacha = (reqPlayGacha)req.parameters; 


        // if (rigged)
        // {
        //     foreach (int id in rigList)
        //     {
        //         gachaLogDetails.Add(new GachaPull{id = id, type = GachaPullType.PERSONALITY});
        //     }
        //     return;
        // }


        if (reqPlayGacha.paymentId <= 1)
        {
            gachaLogDetails.Add(new GachaPull(false)); 
        } else if (reqPlayGacha.paymentId == 2)
        {
            for (int i = 0; i < 9; i++)
            { 
                gachaLogDetails.Add(new GachaPull(false));    
            }

            gachaLogDetails.Add(new GachaPull(true));
        }
        
    }
}

public class GachaPull
{
    public GachaPullItemReward ex {get; set;} = new GachaPullItemReward();
    public int id {get; set;} = 21201;
    public GachaPullType type {get; set;}= GachaPullType.EGO;
    public GachaPull()
    {
        
    }
    public GachaPull(bool guaranteedExtraction)
    {
        var config = AppConfig.GetConfig();
        double announcer = config.GetValue<double>("Gacha:Announcer");
        double ego = config.GetValue<double>("Gacha:EGO");
        double threeStar = config.GetValue<double>("Gacha:ThreeStar");
        double twoStar = config.GetValue<double>("Gacha:TwoStar");
        double oneStar = config.GetValue<double>("Gacha:OneStar");

        int pullType = new FastWeightedSelector<int>([0,1,2,3,4], [announcer, ego, threeStar, twoStar, oneStar]).SelectRandomItem();

        int[] targetList = [];
        switch (pullType)
        {
            case 0: 
                // i don't wanna do this, yo
                break;
            case 1: 
                type = GachaPullType.EGO;
                targetList = StaticSinnerEGOInfo.GetAllEGOIds().ToArray();
                break;
            case 2: 
                type = GachaPullType.PERSONALITY;
                targetList = StaticSinnerPersonalityInfo.Get3StarIDs().ToArray();
                break;
            case 3: 
                type = GachaPullType.PERSONALITY;
                targetList = StaticSinnerPersonalityInfo.Get2StarIDs().ToArray();
                break;
            case 4:
                if (guaranteedExtraction)
                {
                    type = GachaPullType.PERSONALITY;
                    targetList = StaticSinnerPersonalityInfo.Get2StarIDs().ToArray();
                } else
                {
                    type = GachaPullType.PERSONALITY;
                    targetList = StaticSinnerPersonalityInfo.Get1StarIDs().ToArray();
                }
                
                break;
        }

        if (targetList.Length == 0)
        {
            targetList = [10101];
            type = GachaPullType.ITEM;
        }

        id = targetList[Random.Shared.Next(0, targetList.Length)];
    }
}

public class GachaPullItemReward
{
    public int id {get; set;} = 10301;
    public int num {get; set;} = 6767;
    public int tags {get; set;} = 0;
    public GachaPullType type {get; set;} = GachaPullType.ITEM;
}

public enum GachaPullType
{
    ITEM, ANNOUNCER, EGOd, PERSONALITY, EGO
}