import java.lang.reflect.*;

public class Inspector<T> {
	Class<T> inspectedClass;
	public Inspector(Class<T> objClass) {
		this.inspectedClass = objClass;
	}
	public void displayInformations() {
		System.out.println("Information of the \""+  inspectedClass.getName() + "\" class:");
		System.out.println("Superclass: " + inspectedClass.getAnnotatedSuperclass().getType().getTypeName());

		Method[] m = inspectedClass.getDeclaredMethods();
		if (m.length > 0) {
			System.out.println(m.length + " methods:");
			for (int i = 0; i < m.length; i++) {
				System.out.println("- " + m[i].getName());
			}
		}

		Field[] f = inspectedClass.getDeclaredFields();
		if (f.length > 0) {
			System.out.println(f.length + " fields:");
			for (int i = 0; i < f.length; i++) {
				System.out.println("- " + f[i].getName());
			}
		}
	}

	public T createInstance() throws Throwable {
		T newObj = null;
		Class<?>[] exceptionsList;
		Class<?> exception;
		exceptionsList = inspectedClass.getConstructor().getExceptionTypes();
		try {
			newObj = inspectedClass.getConstructor().newInstance();
		}
		catch (Throwable e) {
			for (int i = 0; i < exceptionsList.length; i++) {
				exception = exceptionsList[i];
				System.out.println(exception);
			}
		}
		return (newObj);
	}
}