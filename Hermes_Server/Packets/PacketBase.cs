using System.Reflection.Metadata.Ecma335;
using System.Runtime.InteropServices;
using System.Text.Json;
using Newtonsoft.Json;
using Newtonsoft.Json.Linq;
public class reqPacketBase
{
    // public string path {get; set;} = "";
    // public int packetId {get; set;} = 67;
    // public static async Task<T> CreateAsync<T>(HttpRequest request) where T : reqPacketBase, new()
    // {
    //     using (var reader = new StreamReader(request.Body))
    //     {
    //         string jsonString = await reader.ReadToEndAsync();
    //         var packet = JsonConvert.DeserializeObject<T>(jsonString);

    //         Console.Write($"{typeof(T)}: ");
    //         Console.WriteLine(jsonString);
    //         Console.WriteLine(""); // just another line of space. We love reading!

    //         if (packet != null)
    //         {
    //             // Polymorphic call: executes the child's overridden logic automatically
    //             packet.Init();
                
    //         }

    //         return packet ?? new T();
    //     }
    // }
    // public virtual void Init()
    // {
        
    // }

}

public class resPacketBase
{
    // public int packetId {get; set;} = 67;
    // public string state {get; set;} = "ok";
    
    // public Dictionary<string, string> serverInfo {get; set;} 
    //     = new Dictionary<string, string>{["version"] = "product"};

    // public Dictionary<string, int> result {get; set;} 
    //     = new Dictionary<string, int>{["timeOffset"] = 0};

    // protected void SetPacketID(int pid) => packetId = pid;

    // public resPacketBase(reqPacketBase req)
    // {
    //     packetId = req.packetId;
    // }
    public int test {get; set;} = 0;
}

public class RequestPacket
{
    public long packetId {get; set;} = 67;
    public UserAuth userAuth {get; set;} = new UserAuth();
    public reqPacketBase? parameters {get; set;}
    public static async Task<RequestPacket> CreateAsync<T>(HttpRequest request) where T : reqPacketBase, new()
    {
        using (var reader = new StreamReader(request.Body))
        {
            string jsonString = await reader.ReadToEndAsync();

            var json = JObject.Parse(jsonString);

            var reqPacket = json.ToObject<RequestPacket>();
            reqPacket.parameters = json["parameters"]?.ToObject<T>();
            
            Console.Write($"{typeof(T)}: ");
            Console.WriteLine(jsonString);
            Console.WriteLine(""); // just another line of space. We love reading!

            return reqPacket;
        }
    }
    public RequestPacket()
    {
        
    }
}

public class ResponsePacket
{
    public long packetId {get; set;} = 67;
    public string state {get; set;} = "ok";
    public Dictionary<string, string> serverInfo {get; set;} 
        = new Dictionary<string, string>{["version"] = "product"};

    public resPacketBase result {get; set;} = new resPacketBase();
    public resPacketBase updated {get; set;} = new resPacketBase(); // special! oh god. 
    // public sigma sigma = new sigma();
    public static ResponsePacket Create<T>(RequestPacket requestPacket) where T : resPacketBase
    {
        
        object? resResult = new resPacketBase();
        if (typeof(T) != typeof(resPacketBase))
        {
            resResult = Activator.CreateInstance(typeof(T), requestPacket);
        }

        var resPacket = new ResponsePacket
        {
            result = (T)resResult, // let's hope this works, yeah?
            packetId = requestPacket.packetId
        };

        // Console.WriteLine($"Result: {resPacket.result}");

        // make an exception for this "simple" little fellow!
        if (typeof(T) == typeof(resLoadUserDataAll))
        {
            resPacket.updated = new updatedLoadUserDataAll(requestPacket);
        }

        
        return resPacket;
    }
    public ResponsePacket()
    {
        
    }
}

public class sigma
{
    public int test1 = 10;
    public int test2 = 20;
}