-- 定义回调函数，为多函数提供服务，只需要完成逻辑，不关心别人怎么来调用我
function call_back(value)
	print(value)
end

-- 业务函数，参数为回调函数指针，在内部通过参数执行回调函数的逻辑
function output(key,call_back_func)
    call_back_func(key)
end

function main( ... )
    -- call_back为需要传递过去的参数函数，output通过获取参数执行
    -- 简洁来说就是将函数通过参数的形式传递过去，业务函数根据需求进行调用
    output("callback",call_back)
end
 
main()