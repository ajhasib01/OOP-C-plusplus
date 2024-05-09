# TASKS

**1.** Create a class `Ipv4Address`. Make it store 4 unsigned chars (perhaps in an array?). Write ***getters and setters***. Create a class `Request` which has a private field origin of type `Ipv4Address`. Write a constructor for `Request` that initializes the origin field. Write a public ***getter for origin***, but no setter for origin. Add a method `log` which prints out the message **"Request of unknown type from a.b.c.d"**, where a, b, c, and d are the values of the 4 unsigned chars from `Ipv4Address`.

**2.** Create a class `HttpRequest` which extends Request. Add a field url of type **std::string**. Add ***setters and getters***. Write a constructor that correctly initializes all fields. Override the `log` method which prints out the message `"Http Request of from a.b.c.d to url 'url'"`, where 'url' should be replaced by the contents of the `url` field of the object.

**3.** Create a class `GetRequest` which extends **HttpRequest**. Override the `log` method to print `"Http GET Request of from a.b.c.d to url 'url'"`.

**4.** Create a class `PostRequest` which extends **HttpRequest**. Add a field payload of type `std::string`. Add ***setters and getters***. Override the log method to print "`Http POST Request of from a.b.c.d to url 'url' with payload 'payload'`".