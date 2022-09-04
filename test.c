#include <stdio.h>
#include <json-c/json.h>

int main(int argc, char **argv){
    FILE *fp;
    // char file_buffer[1024];
    char buffer[1024] = {"{\"device_name\": \"JSON2C\", \"settings\": { \"timezone\": \"Taiwan\", \"mode\": \"Dual_Band\", \"model\": \"AP\",\"total_usr\" : 3, \"usr_name\": [\"git\", \"hub\", \"no1\"]}}"};

    struct json_object *parsed;
    struct json_object *device_name;
    struct json_object *settings;
    struct json_object *timezone;
    struct json_object *model;
    struct json_object *mode;
    struct json_object *total_usr;
    struct json_object *usr;

    struct json_object *usr_index;

    size_t n_usr;
    size_t i;

    // fp = fopen("test.json", "r");
    // fread(file_buffer, 1024, 1, fp);
    // fclose(fp);

    // printf("inside the buffer : %s\n",file_buffer);
    // parsed = json_tokener_parse(file_buffer);
    parsed = json_tokener_parse(buffer);
    // printf("inside parsed: %s\n",parsed);

    printf("device_name flag: %d\n",json_object_object_get_ex(parsed, "device_name", &device_name));
    printf("settings flag : %d\n",json_object_object_get_ex(parsed, "settings", &settings));
    printf("time zone flag: %d\n",json_object_object_get_ex(settings, "timezone", &timezone));
    printf("model flag : %d\n",json_object_object_get_ex(settings, "model", &model));
    printf("mode flag: %d\n",json_object_object_get_ex(settings, "mode", &mode));
    printf("total user: %d\n",json_object_object_get_ex(settings, "total_usr", &total_usr));

    printf("Device Name : %s\n",json_object_get_string(device_name));
    printf("time zone : %s\n",json_object_get_string(timezone));
    printf("model : %s\n",json_object_get_string(model));
    printf("mode : %s\n",json_object_get_string(mode));
    printf("cur total user : %d\n",json_object_get_int(total_usr));

    json_object_object_get_ex(settings, "usr_name", &usr);
    n_usr = json_object_array_length(usr);
    printf("Found %lu users\n",n_usr);

    for(i = 0 ; i < n_usr; i++){
        usr_index = json_object_array_get_idx(usr, i);
        printf("%lu. %s\n",i + 1, json_object_get_string(usr_index));
    }

    return 0;
}
