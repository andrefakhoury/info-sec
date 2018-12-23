std::string encryptCaesar(std::string s, int k) {
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] = (s[i]-'a'+k)%26 + 'a';
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] = (s[i]-'A'+k)%26 + 'A';
	}
	return s;
}

std::string decryptCaesar(std::string s, int k) {
	k %= 26;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] = (s[i]-'a'-k+26)%26 + 'a';
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] = (s[i]-'A'-k+26)%26 + 'A';
	}
	return s;
}

std::vector<std::pair<int, std::string> > bruteCaesar(std::string s) {
	std::vector<std::pair<int, std::string> > vec;
	vec.push_back(std::make_pair(0, s)); //original

	for (int i = 1; i < 26; i++)
		vec.push_back(std::make_pair(i, encryptCaesar(s, i)));

	return vec;
}