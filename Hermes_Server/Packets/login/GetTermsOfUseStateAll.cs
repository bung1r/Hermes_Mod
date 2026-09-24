public class reqGetTermsOfUseStateAll : reqPacketBase
{
    public long uid {get; set;} = 0;
}
public class resGetTermsOfUseStateAll : resPacketBase
{
    public List<TermsOfUseState> termsOfUseStateList {get; set;}
    public resGetTermsOfUseStateAll(RequestPacket req) 
    {
        Console.WriteLine("GET TERMS PLEASE");
        termsOfUseStateList = new List<TermsOfUseState>
        {
            new TermsOfUseState{version = 1, state = TERMSOFUSE_STATE.AGREE}, // should automatically skip Terms Of Use? Maybe?
        };

    }
}

public class TermsOfUseState
{
    public int version {get; set;} = 1;
    public TERMSOFUSE_STATE state {get; set;}  = TERMSOFUSE_STATE.AGREE;
}

public enum TERMSOFUSE_STATE { NONE, AGREE, DISAGREE }