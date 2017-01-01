--- SJ version
A :# {
	DoWork :# {
		t : task() {
			j = 5
			j
		}
		t.result
	}
}

--- C# version
public class A {
	public static void DoWork() {
		var t = Task.Run(() => {
			var j = 5;
			return j;
		});
		Task.Wait(t);
	}
}