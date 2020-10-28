template <typename T>
class fenwick { // 1-based indexing (keep 0-based in main)
public:
	T size;
	vector<T > table;

	fenwick(T size) {
		this->size = size+1;
		table.assign(size+1, 0);
	}

	fenwick(vector<T > a) : fenwick(a.size()) {
		for (size_t i = 0; i < a.size(); i++) {
			addin(i, a[i]);
		}
	}

	void addin(T i, T data) {
		for (++i; i < size; i += i & -i) {
			table[i] += data;
		}
	}

	// Update ith value by delta
	void update(T i, T delta) {
		while (i < size) {
			table[i] += delta;
			i += (i & -i);
		}
	}

	// Update l to r inclusive values ny delta
	void update(T l, T r, T delta) {
		addin(l, delta);
		addin(r+1, -delta);
	}

	void change(T i, T change) {
		T prevdata;
		if(i<size) {
			prevdata = table[i];
			table[i]=change;
		}
		T delta=change - prevdata;
		update(i, delta);
	}

	// Compute prefix sum from 1 to i
	T sum(T i) {
		T sum = 0;
		while (i > 0) {
			sum += table[i];
			i -= (i & -i);
		}
		return sum;
	}

	T rangesum(T l, T r) {
		return sum(r) - sum(l-1);
	}
	/* In main()
	1. fenwick<int> bit(a);
	*/
};
