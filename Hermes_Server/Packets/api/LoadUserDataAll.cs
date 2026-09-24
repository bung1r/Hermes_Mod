// this is gonna be mentally damaging. 
public class reqLoadUserDataAll : reqPacketBase
{
    
}

public class resLoadUserDataAll : resPacketBase
{
    // public DateTime secession_Date {get; set;} = new DateTime(2026, 1, 1, 1, 1, 1, 777, DateTimeKind.Utc);
    public ProfileInfoWithSupports profile {get; set;}
    public bool isExistReceiveFriendRequest {get; set;}
    public int danteNoteTodayPage {get; set;} = 49;
    public List<int> dailyLoginRewardStates; // TBD
    public int dailyLoginWeekId {get; set;} = -1;
    public int dailyLoginId {get; set;} = -1;
    public int showedWeekByMinistory {get; set;} = 3;
    public List<int> userbanners; // TBD
    public List<int> leftBorders; // TBD
    public List<int> rightBorders; // TBD
    public List<int> egoBackgrounds; // TBD
    public DateTime date {get; set;} = new DateTime(2026, 1, 1, 1, 1, 1, 777, DateTimeKind.Utc);
    public bool IsExistReceiveFriendRequest {get; set;} = false;
    public resLoadUserDataAll(RequestPacket req) 
    {
        profile = new ProfileInfoWithSupports();
    }
}

public class ProfileInfoWithSupports
{
    public List<BannerDisplayInfo> banners {get; set;} = new List<BannerDisplayInfo>
    {
        new BannerDisplayInfo(), new BannerDisplayInfo(), new BannerDisplayInfo(), new BannerDisplayInfo(), new BannerDisplayInfo()
    };
    public DateTime date {get; set;}= new DateTime(2026, 1, 1, 1, 1, 1, 777, DateTimeKind.Utc);
    public int egobackground_id {get; set;} = 32;
    public int illust_gacksung_level {get; set;} = 3;
    public int illust_id {get; set;} = 11107; 
    public int leftborder_id {get; set;} = 29;
    public int level {get; set;} = 67;
    public string public_uid {get; set;} = "Will Of The City";
    public int rightborder_id {get; set;} = 29;
    public int sentence_id {get; set;} = 231;
    public List<int> support_personalities {get; set;} // haha node
    public int word_id {get; set;} = 116;
}

public class BannerDisplayInfo
{
    public int id {get; set;} = 35;
    public int idx {get; set;} = 0;
    public int value {get; set;} = -1;
    public int value2 {get; set;} = -1;
    public int value3 {get; set;} = -1;
}
// The EVILS!
public class updatedLoadUserDataAll : resPacketBase
{
    public AnnouncerList announcer {get; set;}
    public BattlepassInfo battlePass {get; set;}
    public List<DanteAbilityInfo> danteAbilityList {get; set;}
    public List<EGOInfo> egoList {get; set;}
    public List<FormationInfo> formationList {get; set;}
    public List<ItemInfo> itemList {get; set;}
    public LobbyCG lobbyCG {get; set;}
    public List<MailInfo> mailList {get; set;}
    public List<MainChapterStateList> mainChapterStateList {get; set;}
    public List<PersonalityInfo> personalityList {get; set;}
    public List<PersonalitySkinInfo> personalitySkinList {get; set;}
    public UserInfo userInfo {get; set;}
    public List<UserUnlockCodeInfo> userUnlockCodeList {get; set;}

    public bool membershipList {get; set;}


    public bool isInitialized = true;
    public updatedLoadUserDataAll(RequestPacket req) 
    {
        announcer = new AnnouncerList();
        battlePass = new BattlepassInfo();
        danteAbilityList = new List<DanteAbilityInfo> {
            new DanteAbilityInfo(), new DanteAbilityInfo{category = 1}
        };
        
        egoList = new List<EGOInfo>(); 
        List<int> allEGOIds = StaticSinnerEGOInfo.GetAllEGOIds();
        foreach (int id in allEGOIds)
        {
            egoList.Add(new EGOInfo{ego_id = id});
        }

        // OH MY GOD IT'S HAPPENING 1

        formationList = new List<FormationInfo>
        {
            new FormationInfo()
        };

        itemList = new List<ItemInfo>
        {
            new ItemInfo{item_id = 1, num = 420000},
            new ItemInfo{item_id = 2, num = 420000},
            new ItemInfo{item_id = 3, num = 99},
            new ItemInfo{item_id = 4, num = 99},
            new ItemInfo{item_id = 5, num = 99},
            new ItemInfo{item_id = 6, num = 99},
            new ItemInfo{item_id = 7, num = 99},
        };

        lobbyCG = new LobbyCG();

        mailList = new List<MailInfo>
        {
            new MailInfo()
        };
        // OH MY GOD OH MY GOD!!

        // // this hurt a lot to do. jesus christ. 
        mainChapterStateList = new List<MainChapterStateList>
        {
            new MainChapterStateList(1),
            new MainChapterStateList(91)
        };

        personalityList = new List<PersonalityInfo>(); 
        List<int> allPersonalityIds = StaticSinnerPersonalityInfo.GetAllPersonalityIDs();
        foreach (int id in allPersonalityIds)
        {
            personalityList.Add(new PersonalityInfo{personality_id = id});
        }

        personalitySkinList = new List<PersonalitySkinInfo>();

        userInfo = new UserInfo();
        
        userUnlockCodeList = new List<UserUnlockCodeInfo>(); // If you've unlocked the chapter, basically
        for (int i = 0; i < StaticChapterInfo.MainChapterNodeCounts.Count; i++)
        {
            int id = 100 + i;
            userUnlockCodeList.Add(new UserUnlockCodeInfo{unlockcode = id});
        }
        for (int i = 0; i < StaticChapterInfo.SideChapterNodeCounts.Count; i++)
        {
            int id = 9100 + i;
            userUnlockCodeList.Add(new UserUnlockCodeInfo{unlockcode = id});
        }

    }
}

public class AnnouncerList
{
    public List<int> announcer_ids {get; set;}
    public List<int> cur_announcer_ids {get; set;}
    public AnnouncerList () {
        announcer_ids = new List<int>();
        for (int i = 0; i < 100; i++) announcer_ids.Add(i);
        cur_announcer_ids = new List<int>();
    }
}

public class BattlepassInfo
{
    // limbus is this context means the Limbus Paid Pass
    public int ex_reward_level {get; set;} = 0;
    public int ex_reward_limbus_level {get; set;} = 0;
    public int exp {get; set;} = 0;
    public bool is_limbus {get; set;} = true;
    public int limbus_apply_level {get; set;} = 0;
    public List<bool> missions_state {get; set;} // idk about this one chief
    public List<bool> rewards_state {get; set;} // idk about this one chief 
    public int special_product_state {get; set;} = 0;
    public int today_rand_value {get; set;} = 12; // what is this???
}

public class DanteAbilityInfo
{
    public List<int> abilityids {get; set;} = new List<int>
    {
        90101, 80101, 70101, 10102, 60101
    };
    public int category {get; set;} = 0;
    public int remaincount {get; set;} = 67;
}

public class EGOInfo
{
    DateTime acquire_time {get; set;} = new DateTime(2025, 6, 7, 4, 20, 6, 777, DateTimeKind.Utc);
    public int ego_id {get; set;} = 20101; // ids are formatted like 2XXYY, where XX = Sinner, YY = EGO uid.
    public int gacksung {get; set;} = 4; // this is most likely uptie. 
}

public class FormationInfo
{
    public List<FormationDetails> formationDetails {get; set;} = new List<FormationDetails>();
    public string formationNameFormat {get; set;} // umm idK??? I know what this is, but idk the data type or anything
    public int id {get; set;} = 0;
    public FormationInfo() // 1 = Yi, 12 = Greg
    {
        for (int i = 1; i < 13; i++) formationDetails.Add(new FormationDetails(i));
    }
}

public class FormationDetails {
    public List<int> egos {get; set;} = new List<int>()
    {
        20101, // ZAYIN
        0, // TETH
        0, // HE
        0, // WAW
        0, // ALEPH
    };
    public bool isParticipated {get; set;} = false;
    public int participationOrder {get; set;} = 0;
    public int personalityId {get; set;} = 10101;
    public FormationDetails (int sinner) {
        egos[0] = 20000 + sinner * 100 + 1;
        personalityId = 10000 + sinner * 100 + 1;
    }
}

public class ItemInfo
{
    public int item_id {get; set;} = 1;
    public int num {get; set;} = 99;
}

public class LobbyCG
{
    public int characterId {get; set;} = 1;
    public bool isShowProfile {get; set;} = true;
    public LobbyCGDetails lobbycgdetails {get; set;}    
}

public class LobbyCGDetails
{
    
}

public class MailInfo
{
    public List<MailAttachment> attachments {get; set;} = new List<MailAttachment>
    {
        new MailAttachment()
    };
    public int content_id {get; set;} = 5860;
    public DateTime expiry_date {get; set;}= new DateTime(2050, 1, 1, 1, 1, 1, 777, DateTimeKind.Utc);
    public int mail_id {get; set;}= 1;
    // public int parameters idk what this is
    public DateTime sent_date {get; set;} = new DateTime(2025, 1, 1, 1, 1, 1, 777, DateTimeKind.Utc);
}

public class MailAttachment
{
    public int id {get; set;} = 1;
    public int num {get; set;} = 1300;
    public int tags {get; set;}
    public MailAttachmentType type {get; set;} = MailAttachmentType.ITEM;
}

public enum MailAttachmentType {ITEM}
public class MainChapterStateList
{
    public int id {get; set;} = 1;
    public List<ChapterCompletionInfo> subcss {get; set;}
    public MainChapterStateList (int id)
    {
        this.id = id;
        subcss = new List<ChapterCompletionInfo>();
        if (id == 1)
        {
            for (int i = 0; i < StaticChapterInfo.MainChapterNodeCounts.Count; i++)
            {
                int v = StaticChapterInfo.MainChapterNodeCounts[i];
                subcss.Add(new ChapterCompletionInfo(i, v, id));
            }
        } else if (id == 91)
        {
            for (int i = 0; i < StaticChapterInfo.SideChapterNodeCounts.Count; i++)
            {
                int v = StaticChapterInfo.SideChapterNodeCounts[i];
                subcss.Add(new ChapterCompletionInfo(i, v, id));
            }
        } else
        {
            // idk man go muck yourself
        }
    }
}

public class ChapterCompletionInfo
{
    public int id {get; set;} = 100;
    public List<ChapterNodeCompletionInfo> nss {get; set;}
    public List<int> rss {get; set;} = new List<int>
    {
        1,
        2,
        3,
        10
    }; // i think these are the EX Rewards?
    public ChapterCompletionInfo(int canto, int nodeNum, int id)
    {
        this.id = id * 100 + canto;
        nss = new List<ChapterNodeCompletionInfo>();
        for (int i = 0; i < nodeNum; i++)
        {
            nss.Add(new ChapterNodeCompletionInfo{id = this.id * 100 + i + 1});
        }
    }
}

public class ChapterNodeCompletionInfo
{
    public int cn {get; set;} = 1; // ???
    public int ct {get; set;} = 2; // ???
    public int dn {get; set;} = 0; // ???
    public int id {get; set;} = 10001; // id of the node
}

public class PersonalityInfo
{
    DateTime acquire_time {get; set;} = new DateTime(2025, 1, 1, 1, 1, 1, 777, DateTimeKind.Utc);
    public int exp {get; set;} = 0;
    public int gacksung {get; set;} = 4; // this is most likely uptie. 
    public int gacksung_illust_type {get; set;} = 1;
    public int level {get; set;} = 99;
    public int order_id {get; set;} = 0;
    public int personality_id {get; set;} = 10101; // ids are formatted like 1XXYY, where XX = Sinner, YY = ID uid.
}

public class PersonalitySkinInfo
{
    public int id {get; set;} = 10101; // fuck this bro, i'm not adding this
    // public string regdate {get;}
}

public class UserInfo
{
    public int exp {get; set;} = 0;
    public int stamina {get; set;} = 99999;
    public DateTime first_login_today {get; set;} = new DateTime(2025, 1, 1, 1, 1, 1, 777, DateTimeKind.Utc);
    public DateTime last_stamina_recover {get; set;} = new DateTime(2025, 1, 1, 1, 1, 1, 777, DateTimeKind.Utc);
    public int level {get; set;} = 67;
    public int uid {get; set;} = 676767;
}

public class UserUnlockCodeInfo {
    public DateTime expireDate {get; set;} = new DateTime(2050, 1, 1, 1, 1, 1, 777, DateTimeKind.Utc);
    public int unlockcode {get; set;}
}