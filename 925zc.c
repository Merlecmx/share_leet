bool isLongPressedName(char *name, char *typed) {
    int name_index = 0;
    int typed_index = 0;
    while (name[name_index] != '\0') {
        if( name[name_index + 1] != name[name_index]) {
            if (name[name_index] != typed[typed_index])
                return false;
            while (typed[typed_index+1] == name[name_index])
                typed_index++;//将typed的下标移动到与name的值不相等的前一个位置
        } else if (typed[typed_index] != name[name_index])
            return false;//对应位置的值不相等直接false
        name_index++;
        typed_index++;
    }
    return true;
}
