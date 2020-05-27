template<typename IT, typename T>
T sum(IT begin, IT end, T zero) {
	T result = zero;
	for(;begin!=end; ++begin) {
		result += (*begin);
	}
	return result;
}