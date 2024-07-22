"use client";
import React from "react";
import classes from "@/styles/CustomInputField.module.css";

type CustomInputFieldProps = {
  placeholder: string;
  type: string;
  value: string | number;
  id: string;
  handleChanges: (
    e:
      | React.ChangeEvent<HTMLInputElement>
      | React.ChangeEvent<HTMLTextAreaElement>
      | any
  ) => void;
  onBlur?: () => void;
  error?: string;
};

const CustomInputField: React.FC<CustomInputFieldProps> = ({
  placeholder,
  type,
  value,
  id,
  handleChanges,
  onBlur,
  error,
}) => {
  return (
    <div className={classes["container"]}>
      <div className={classes["box"]}>
        <input
          placeholder=" "
          type={type}
          value={value}
          id={id}
          onChange={handleChanges}
          onBlur={onBlur}
          style={{
            borderColor: error ? "var(--light-warn-color)" : "",
          }}
        />
        <label>
          {error ? (
            <span className={classes["error"]}>{error}</span>
          ) : (
            <span>{placeholder}</span>
          )}
        </label>
      </div>
    </div>
  );
};

export default CustomInputField;
