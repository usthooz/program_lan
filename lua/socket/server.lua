-- 加载模块
socket = require("socket");
-- server host
host = host or "127.0.0.1";
-- listent port
port = port or "8080";
-- accept anf bind
server = assert(socket.bind(host, port));
-- 
ack = "ooz...\n";
while 1 do
    print("waiting client conn...");
    -- accept client connnection
    control = assert(server:accept());
    while 1 do 
        command,status = control:receive();
  	if status == "closed" then 
		break 
	end
        print(command);
        control:send(ack);
    end
end