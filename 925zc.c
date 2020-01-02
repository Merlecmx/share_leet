bool isLongPressedName(char *name, char *typed) {
    int name_index = 0;
    int typed_index = 0;
    while (name[name_index] != '\0') {
        if( name[name_index + 1] != name[name_index]) {
            if (name[name_index] != typed[typed_index])
                return false;
            while (typed[typed_index+1] == name[name_index])
                typed_index++;//��typed���±��ƶ�����name��ֵ����ȵ�ǰһ��λ��
        } else if (typed[typed_index] != name[name_index])
            return false;//��Ӧλ�õ�ֵ�����ֱ��false
        name_index++;
        typed_index++;
    }
    return true;
}
