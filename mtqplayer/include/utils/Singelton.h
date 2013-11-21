#pragma once

#include <QMutexLocker>

#define MTQ_SINGELTON(ClassT) \
	public: \
		static ClassT& instance() \
		{ \
			return Singelton<ClassT>::instance(); \
		} \
	friend class Singelton<ClassT>;

namespace mtq {

	template <class ClassT>
	class Singelton
	{
	public:
		static ClassT& instance()
		{
			static QMutex mutex;
			static ClassT *instance;

			if (!instance) {
				QMutexLocker locker(&mutex);
				if (!instance)
					instance = new ClassT();
			}

			return *instance;
		}

		~Singelton()
		{
			if (instance)
				delete instance;
			instance = NULL;
		}

	private:
		Singelton();
	};

}
