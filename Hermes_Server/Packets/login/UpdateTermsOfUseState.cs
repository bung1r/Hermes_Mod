public class reqUpdateTermsOfUseState : reqPacketBase
{
    public int uid {get; set;} = 0;
    public int termsVersion {get; set;} = 1;
    public int state {get; set;} = 1;
}

public class resUpdateTermsOfUseState : resPacketBase
{
    public resUpdateTermsOfUseState(RequestPacket req)
    {
        
    }
}