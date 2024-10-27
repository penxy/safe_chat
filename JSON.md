# json
```json
/* global */
/* all json have this */
{
    "check":{
        "crc": "xxx",
    }
}


/* regiest */
{
    "type": "E_Type::Request",
    "func": "E_Action::Regiest",
    "main": {
        "name": "xxx",
        "password": "xxx",
        "date": "xxx"
    }
}
/* Add/Delete/Accept/Reject/Find */
{
    "type" : "E_Type::Request",
    "func" : "E_Send::Action",
    "action": "E_Action::Add",
    "info"{
        "info_you" : {
            "Identity" : "E_Identity::Friend",
            "id" : "xxx",
            "name" : "xxx",
        },
        "info_me" : {
            "name" : "xxx",
            "id" : "xxx",
            "date" : "xxx",
        }
    }
}
/* Text */
{
    "type" : "E_Type::Request",
    "func" : "E_Send::Message",
    "info" :{
        "info_you":{
            "identity" : "E_Identity::Friend",
            "id": "xxx"
        },
        "info_me":{
            "id": "xxx",
        },
        "info_data":{
            "type": "E_Message::Text",
            "date": "xxx",
            "msg":"xxx",
        },
    },
}
/* Status */
{
    "type" : "E_Type::Request",
    "func" : "E_Send::Action",
    "action": "E_Action::Status",
    "info" : {
        "info_you":{
            "identity" : "E_Identity::Friend",
            "id": "xxx"
        },
        "info_me":{
            "id": "xxx",
        },
        "info_status":{
            "status": "E_Status::Online",
        },
    },
}
/* FILE */
{
    "type" : "E_Send::File",
    "action" : "E_File::Up",
    "info":{
        "file" : "???",//template not know how to define
        "file_size" : "xxx",
        "date" : "xxx",
        "md5" : "xxx",
    },
}
{
    "type" : "E_Send::File",
    "action" : "E_File::Down",
    "info":{
        "file_name" : "xxx",
        "save_path" : "xxx"        
    },
}

/* Change info */
{
    "type" : "E_Send::Action",
    "action": "E_Action::ChangeInfo",
    "info":{
        "type":"E_ChangeInfo::Name",
        "info_old":{
            "name" : "xxx",
        },
        "info_new":{
            "name" : "xxx",
        },
    },
}


```


```



# 补充
- 表情包转换为%xx