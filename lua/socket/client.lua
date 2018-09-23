-- load socket module
local socket = require("socket")
host = "127.0.0.1"
port = 8080
-- open a client connection
c = assert (socket.connect (host, port))
c:send ("client send msg... \n")
i = 0 
while (true) do
 local s, status, partial = c:receive ()
 print(s)
 if status == "closed" then 
	break 
 end
 i = i + 1
 if i == 10 then
    print("Connection closed")
	c:close();
 end
 c:send ("GET \n")
end
 
c:close ()
