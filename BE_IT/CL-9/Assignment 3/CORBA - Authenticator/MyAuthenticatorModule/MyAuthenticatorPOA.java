package MyAuthenticatorModule;


/**
* MyAuthenticatorModule/MyAuthenticatorPOA.java .
* Generated by the IDL-to-Java compiler (portable), version "3.2"
* from MyAuthenticatorModule.idl
* Wednesday, 10 March, 2021 1:29:57 PM IST
*/

public abstract class MyAuthenticatorPOA extends org.omg.PortableServer.Servant
 implements MyAuthenticatorModule.MyAuthenticatorOperations, org.omg.CORBA.portable.InvokeHandler
{

  // Constructors

  private static java.util.Hashtable _methods = new java.util.Hashtable ();
  static
  {
    _methods.put ("chech_credentials", new java.lang.Integer (0));
  }

  public org.omg.CORBA.portable.OutputStream _invoke (String $method,
                                org.omg.CORBA.portable.InputStream in,
                                org.omg.CORBA.portable.ResponseHandler $rh)
  {
    org.omg.CORBA.portable.OutputStream out = null;
    java.lang.Integer __method = (java.lang.Integer)_methods.get ($method);
    if (__method == null)
      throw new org.omg.CORBA.BAD_OPERATION (0, org.omg.CORBA.CompletionStatus.COMPLETED_MAYBE);

    switch (__method.intValue ())
    {
       case 0:  // MyAuthenticatorModule/MyAuthenticator/chech_credentials
       {
         String username = in.read_string ();
         String password = in.read_string ();
         String $result = null;
         $result = this.chech_credentials (username, password);
         out = $rh.createReply();
         out.write_string ($result);
         break;
       }

       default:
         throw new org.omg.CORBA.BAD_OPERATION (0, org.omg.CORBA.CompletionStatus.COMPLETED_MAYBE);
    }

    return out;
  } // _invoke

  // Type-specific CORBA::Object operations
  private static String[] __ids = {
    "IDL:MyAuthenticatorModule/MyAuthenticator:1.0"};

  public String[] _all_interfaces (org.omg.PortableServer.POA poa, byte[] objectId)
  {
    return (String[])__ids.clone ();
  }

  public MyAuthenticator _this() 
  {
    return MyAuthenticatorHelper.narrow(
    super._this_object());
  }

  public MyAuthenticator _this(org.omg.CORBA.ORB orb) 
  {
    return MyAuthenticatorHelper.narrow(
    super._this_object(orb));
  }


} // class MyAuthenticatorPOA
